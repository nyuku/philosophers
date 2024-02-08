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
	struct	timeval time;

	gettimeofday(&time, NULL);
	unsigned long long current_time = (unsigned long long )(time.tv_sec * 1000) + (unsigned long long )(time.tv_usec / 1000); // Convertir en millisecondes

	// Vérifier si le philosophe est en train de mourir de faim
	if (((current_time - philo->time_last_meal) > begin->time_to_eat) || ((philo->old_time_last_meal) - (philo->time_last_meal) > begin->time_to_eat))
	{
		return ERROR; // Le philosophe est en train de mourir de faim
	}

	return SUCCESS; // Le philosophe est en sécurité
}



void *keep_an_eye(void *arg)
{
	// t_eye_arg *eye_arg = (t_eye_arg *)arg;  // Cast de void* à t_eye_arg*
	// t_philo *philo;
	int philosophers;
	int all_lunch_eaten;
	pthread_mutex_t m_lunch_eaten;

	all_lunch_eaten = 0;
	philosophers = 0;  // Commencer à 0 si les indices commencent à 0
	philo = eye_arg->philo;
	t_begin *begin = eye_arg->begin;

	while (1)
	{
		printf("im watching\n");
		if (all_lunch_eaten == begin->nb_philo)
		{
			printf("stop_diner here\n");
			break; // Sortir de la boucle si le dîner est terminé
		}
		while (philosophers < begin->nb_philo)
		{ // Assurer que les indices sont corrects
			if (starving(philo, begin) == ERROR)
			{
				printf("someone is dead here\n");
				return (NULL); // Arrêter le thread si un philosophersophe est mort
			}
			pthread_mutex_lock(&m_lunch_eaten); // Utiliser le bon mutex
			if (philo[philosophers].ticket_repas == begin->nb_lunch) // Vérifier si philosophersophe a fini de manger
				all_lunch_eaten++;
			pthread_mutex_unlock(&m_lunch_eaten);
			philosophers++;
		}
		philosophers = 0; // Réinitialiser le compteur pour le prochain tour de la boucle
	}

	free(eye_arg); // Libérer la mémoire allouée pour eye_arg
	return NULL;
}
