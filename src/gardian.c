#include "../includes/philosophers.h"
/*
 * Role: Keep an eye on all philosophers. To check if
 * - they're dying
 * - or full.
 * routine for the threads gardian
 */




void *keep_an_eye(void *arg)
{
    t_eye_arg *eye_arg = (t_eye_arg *)arg;
    t_philo *current;
    t_begin *begin = eye_arg->begin;
	t_mutex *mutex = eye_arg->mutex;
    int all_lunch_eaten = 0;
	(void)mutex;
    while (1) 
	{
        current = eye_arg->philo; // Commence à vérifier depuis le premier philosophe
		if (all_lunch_eaten == begin->nb_philo) 
		{
            printf("Fin du buffet\n");
            break; // Sortir de la boucle si tous les philosophes ont terminé de manger
        } 
        while (current != NULL) 
		{ 
            
            pthread_mutex_lock(&current->time_last_meal_mutex);
			unsigned long long int time_since_last_meal = time_dif(begin->start_time) - current->time_last_meal ;
			pthread_mutex_unlock(&current->time_last_meal_mutex);

            if ((time_since_last_meal > (unsigned long long)begin->time_to_die) && current->time_last_meal != 0)
			{
				printf("qq est mooort\n");
				//pthread_mutex_lock(mutex->m_fatality);
       			if (begin->fatality == 0)
                    begin->fatality = 1;
                current->stop = 1;
        		
				
				printf("%llu\t someone is dead here, philo %d at %llu late time\n",time_dif(begin->start_time), current->order,(time_since_last_meal - begin->time_to_die));
                return (NULL); // Arrêter si un philosophe est mort
            }

            if (current->belly_full == 1) 
			{
                all_lunch_eaten++;
                current->belly_full = 0; // Marquer comme compté pour ne pas réincrémenter all_lunch_eaten
            }

            current = current->next;
        }

    }

    return NULL;
}
