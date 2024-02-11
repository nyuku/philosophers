#include "../includes/philosophers.h"
/*
 * philo doit pouvoir faire un retour sur plusieurs aspect
 * -dernier fois qu'il a mangé
 * s'il a 2 fourchette
 * s'il a deja eu tous ses repas
 *
 * like statut
 * !! si pas de 5e argument.. ne pas compter dessus dans la routine-> set en negatif sinon
 * */

void *routine(void *arg)
{
    t_eye_arg *eye_arg = (t_eye_arg *)arg;
    t_philo *philo = eye_arg->philo;
    t_begin *begin = eye_arg->begin;
    t_mutex *mutex = eye_arg->mutex;
    if (philo->order % 2)// si paire on fait commencer les paires?
		usleep(3000);//3 millisecondes
		
	while (1)
	{
		// objectif de repas, permettant à ce philosophe de "se retirer" de la simulation
		if (!philo->ticket_repas)// encore a table?
			break;
        pthread_mutex_lock(mutex->m_fatality);
        if (begin->fatality == 0)
        {
            pthread_mutex_unlock(mutex->m_fatality);
            go_eat(begin, philo, mutex);
            go_sleep(begin, philo, mutex);
            go_think(begin, philo, mutex);
        }
        else
        {
                printf("faut que j'arrete je suis %d\n",philo->order);
                pthread_mutex_unlock(mutex->m_fatality);
                break;
        }
	}
    // printf("rayayayayayya\n");
            // pthread_mutex_unlock(mutex->m_fatality);
            // return; // Sortie anticipée si fatality est déclenché
    return NULL;
}

void go_eat(t_begin *begin, t_philo *philo, t_mutex *mutex)// !! pas de secu pour print
{
    (void)mutex;// Prendre les fourchettes
    pthread_mutex_lock(mutex->m_fatality);
    if (begin->fatality == 1)
    {
        pthread_mutex_unlock(mutex->m_fatality);
        return;
    }
    pthread_mutex_unlock(mutex->m_fatality);

    pthread_mutex_lock(philo->own_fork); 
    printf("%llu\t %sPhilo %d \ta pris la fourchette gauche\n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    pthread_mutex_lock(philo->right_fork); 
    printf("%llu\t %sPhilo %d \ta pris la fourchette droite\n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    // change time last_meal
    pthread_mutex_lock(&philo->time_last_meal_mutex);
    philo->time_last_meal = time_dif(begin->start_time); // Mettre à jour le temps du dernier repas
    pthread_mutex_unlock(&philo->time_last_meal_mutex);

    philo->ticket_repas--; // decrémenter le compteur de repas
    printf("%llu\t %sPhilo %d \test en train de manger\n"COLOR_RESET, time_dif(begin->start_time),get_philo_color(philo->order), philo->order);

    usleep(begin->time_to_eat); 

    // Libérer les fourchettes
    pthread_mutex_unlock(philo->own_fork);
    pthread_mutex_unlock(philo->right_fork);

    // Vérifier si le philosophe a terminé ses repas
    if (philo->ticket_repas == 0) 
        {
            philo->belly_full = 1;
            return;
        }
             // Indiquer que le philosophe a terminé de manger

}

void go_sleep(t_begin *begin,t_philo *philo, t_mutex *mutex) 
{
    (void)mutex;
    (void)philo;
    pthread_mutex_lock(mutex->m_fatality);
    if (begin->fatality == 1)
    {
       printf("paf fini dde dormir\n");
       pthread_mutex_unlock(mutex->m_fatality);
        return; // Sortie anticipée si fatality est déclenché
    }
    pthread_mutex_unlock(mutex->m_fatality);

    pthread_mutex_lock(mutex->printing);
    printf("%llu\t %sPhilo %d \tfait une sieste\n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    pthread_mutex_unlock(mutex->printing);
    usleep(begin->time_to_sleep * 1000); // Converti en microsecondes
    
}

void go_think(t_begin *begin,t_philo *philo, t_mutex *mutex)

{
    (void)mutex;
    (void)philo;
    pthread_mutex_lock(mutex->m_fatality);
    if (begin->fatality == 1)
    {
       printf("fini de penser\n");
       pthread_mutex_unlock(mutex->m_fatality);
        return; // Sortie anticipée si fatality est déclenché
    }
    pthread_mutex_unlock(mutex->m_fatality);

    pthread_mutex_lock(mutex->printing);
    printf("%llu\t %sPhilo %d\tréfléchi \n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    pthread_mutex_unlock(mutex->printing);
}