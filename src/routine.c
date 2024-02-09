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
    //printf("coucou je suis le philou %d\n", philo->order);
	
	
	while(1)// ou condition de mort non null while (!death_announce)
	{
		// objectif de repas, permettant à ce philosophe de "se retirer" de la simulation
		if (!philo->ticket_repas)// encore a table?
			break;
		go_eat(begin, philo, mutex);
		go_sleep(begin, philo, mutex);
		go_think(philo, mutex, begin);
	}
    return NULL;
}

void go_eat(t_begin *begin, t_philo *philo, t_mutex *mutex)// !! pas de secu pour print
{
    
    (void)mutex;// Prendre les fourchettes
    pthread_mutex_lock(philo->own_fork); // Verrouiller Sa fourchette (gauche)
    //printf("%llu\t Philo %d \ta pris la fourchette gauche\n", time_dif(begin->start_time), philo->order);
    printf("%llu\t %sPhilo %d \ta pris la fourchette gauche\n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    pthread_mutex_lock(philo->right_fork); // Verrouiller la fourchette droite
    //printf("%llu\t Philo %d \ta pris la fourchette droite\n", time_dif(begin->start_time), philo->order);
    printf("%llu\t %sPhilo %d \ta pris la fourchette droite\n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    // Manger
    //philo->old_time_last_meal = philo->time_last_meal;
    philo->time_last_meal = time_dif(begin->start_time); // Mettre à jour le temps du dernier repas
    philo->ticket_repas--; // decrémenter le compteur de repas
    printf("%llu\t %sPhilo %d \test en train de manger\n"COLOR_RESET, time_dif(begin->start_time),get_philo_color(philo->order), philo->order);

    usleep(begin->time_to_eat); // Le philosophe mange pendant un certain temps
    // Libérer les fourchettes
    pthread_mutex_unlock(philo->own_fork);
    pthread_mutex_unlock(philo->right_fork);

    // Vérifier si le philosophe a terminé ses repas
    if (philo->ticket_repas == 0) 
    {
       // pthread_mutex_lock(&(philo->mutex));
        philo->belly_full = 1; // Indiquer que le philosophe a terminé de manger
       // pthread_mutex_unlock(&(philo->mutex));
    }
}

void go_sleep(t_begin *begin,t_philo *philo, t_mutex *mutex) 
{
    (void)mutex;
    (void)philo;
    pthread_mutex_lock(mutex->printing);// lock pour print
    // printf("%llu\t Philo %d \tfait une sieste\n", time_dif(begin->start_time), philo->order);
     printf("%llu\t %sPhilo %d \tfait une sieste\n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    pthread_mutex_unlock(mutex->printing);
    
    // Simulation du sommeil
    usleep(begin->time_to_sleep * 1000); // Converti en microsecondes
    
}

void go_think(t_philo *philo,t_mutex *mutex,t_begin *begin)
{
    (void)mutex;
    (void)philo;

    pthread_mutex_lock(mutex->printing);// lock pour print
    //printf("%llu\t Philo %d\t réfléchi \n", time_dif(begin->start_time), philo->order);
   
    printf("%llu\t %sPhilo %d\tréfléchi \n" COLOR_RESET, time_dif(begin->start_time), get_philo_color(philo->order), philo->order);
    pthread_mutex_unlock(mutex->printing);
    
    //attend une fourchette, des qu'il en a une -> eat
}