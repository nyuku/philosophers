#include "../includes/philosophers.h"
/*
 * Role: Keep an eye on all philosophers. To check if
 * - they're dying
 * - or full.
 * routine for the threads gardian
 */

void print_log(int time, char *message, int ph_id, pthread_mutex_t *print_mutex, t_philo *philo) 
{
    pthread_mutex_lock(print_mutex);
    if (!philo->stop) { // Supposons que `stop_global` est une variable globale partagée contrôlée par le gardien
        printf("%d %d %s\n", time, ph_id, message);
    }
    pthread_mutex_unlock(print_mutex);
}


int starving(t_philo *philo, t_begin *begin)// check entre les repas...pas temps actuel
{
	//struct	timeval time;

	// gettimeofday(&time, NULL);
	// unsigned long long current_time = (unsigned long long )(time.tv_sec * 1000) + (unsigned long long )(time.tv_usec / 1000); // Convertir en millisecondes
	unsigned long long int time_satrving = 0;
	time_satrving = time_dif(philo->old_time_last_meal);
	// Vérifier si le philosophe est en train de mourir de faim
	if (time_satrving > begin->time_to_eat) 
	{
		return ERROR; // Le philosophe est en train de mourir de faim
	}

	return SUCCESS; // Le philosophe est en sécurité
}

void *keep_an_eye(void *arg) {
    t_eye_arg *eye_arg = (t_eye_arg *)arg;
    t_philo *current;
    t_begin *begin = eye_arg->begin;
    int all_lunch_eaten = 0;

    while (1) {
        current = eye_arg->philo; // Commence à vérifier depuis le premier philosophe

        while (current != NULL) { 
            unsigned long long int time_since_last_meal = time_dif(begin->start_time) -current->time_last_meal ;

            if ((time_since_last_meal > (unsigned long long)begin->time_to_die) && current->time_last_meal != 0)
			{
                printf("time_since_last_meal calculé %llu\n", time_since_last_meal);
				printf("time last meal %llu\n", current->time_last_meal);
				printf("begin->time_to_die %d\n",begin->time_to_die);
				printf("someone is dead here, philo %d\n",current->order);
                return (NULL); // Arrêter si un philosophe est mort
            }

            if (current->belly_full == 1) {
                all_lunch_eaten++;
                current->belly_full = 0; // Marquer comme compté pour ne pas réincrémenter all_lunch_eaten
            }

            current = current->next;
        }

        if (all_lunch_eaten == begin->nb_philo) {
            printf("Fin du buffet\n");
            break; // Sortir de la boucle si tous les philosophes ont terminé de manger
        } else {
            // Si tous les philosophes n'ont pas fini, réinitialise all_lunch_eaten pour le prochain tour
            all_lunch_eaten = 0;
        }

        usleep(10000); // Attente courte pour réduire la consommation CPU
    }

    return NULL;
}


// void *keep_an_eye(void *arg)
// {
// 	 t_eye_arg *eye_arg = (t_eye_arg *)arg;
// 	// t_philo *philo;
// 	int all_lunch_eaten;
// 	//pthread_mutex_t m_lunch_eaten;

// 	all_lunch_eaten = 0;
// 	t_philo *current; // Commencer à 0 si les indices commencent à 0
	
// 	t_begin *begin = eye_arg->begin;

// 	while (1)
// 	{
// 		printf("im watching\n");
// 		current = eye_arg->philo;
// 		if (all_lunch_eaten == begin->nb_philo)
// 		{
// 			printf("stop_diner here\n");
// 			return(NULL); // Sortir de la boucle si le dîner est terminé
// 		}
// 		while (current!= NULL)
// 		{ 
// 			unsigned long long int time_starving = ((time_dif(begin->start_time)) -(current->time_last_meal) ) ;
// 			// printf("temps de survie %llu\n", begin->time_to_eat);
// 			// printf("time_starving current %llu\n", time_starving);
// 			// printf("last meal %llu\n",current->time_last_meal);
// 			//soucis avec le time last meal
// 			if ((time_starving > begin->time_to_eat) && current->time_last_meal != 0)
// 			{
// 				printf("someone is dead here\n");
// 				return (NULL); // Arrêter le thread si un philosophersophe est mort
// 			}
// 			//pthread_mutex_lock(&m_lunch_eaten); // Utiliser le bon mutex
// 			if (current->belly_full == 1) // Vérifier si philosophersophe a fini de manger
// 			{
// 				all_lunch_eaten++;
// 				current->belly_full = 0; // pour le compte 1 fois.. ona le ticket repas pour le philo pour qu'il arrete.. et belly full comme switch
// 			}
// 			//pthread_mutex_unlock(&m_lunch_eaten);
// 			current = current->next;
// 		}
// 		// Réinitialiser le compteur pour le prochain tour de la boucle
// 	}

// 	free(eye_arg); // Libérer la mémoire allouée pour eye_arg
// 	return NULL;
// }
