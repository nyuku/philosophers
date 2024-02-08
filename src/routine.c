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
	
	while(1)// ou condition de mort non null while (!death_announce)
	{
		// objectif de repas, permettant à ce philosophe de "se retirer" de la simulation
		if (!philo->ticket_repas)// encore a table?
			break;
		go_eat(begin, philo, mutex);
		go_sleep(begin, philo, mutex);
		go_think(begin, philo, mutex);
	}
    return NULL;
}

void go_eat(t_begin *begin, t_philo *philo, t_mutex *mutex)// !! pas de secu pour print
{
    
    (void)mutex;// Prendre les fourchettes
    pthread_mutex_lock(philo->own_fork); // Verrouiller Sa fourchette (gauche)
    printf("Philo %d a pris la fourchette gauche\n" ,begin->nb_philo);
    pthread_mutex_lock(philo->right_fork); // Verrouiller la fourchette droite
    printf("Philo %d a pris la fourchette droite\n",begin->nb_philo);

    // Manger
    philo->time_last_meal = get_current_time(); // Mettre à jour le temps du dernier repas
    philo->ticket_repas--; // decrémenter le compteur de repas
    printf("Philo %d est en train de manger\n", begin->nb_philo);
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

void go_sleep(t_begin *begin, t_philo *philo, t_mutex *mutex) 
{
    (void)mutex;
    (void)philo;
    pthread_mutex_lock(mutex->printing);// lock pour print
    printf("Philo %d starts sleeping\n", begin->nb_philo);
    //print_log(philo)
    pthread_mutex_unlock(mutex->printing);
    
    // Simulation du sommeil
    usleep(begin->time_to_sleep * 1000); // Converti en microsecondes
    
}

void go_think(t_begin *begin, t_philo *philo,t_mutex *mutex)
{
    (void)mutex;
    (void)philo;

    pthread_mutex_lock(mutex->printing);// lock pour print
    printf("Philo %d starts thinking\n", begin->nb_philo);
    //print_log(philo)//
    pthread_mutex_unlock(mutex->printing);
    
    //attend une fourchette, des qu'il en a une -> eat
}