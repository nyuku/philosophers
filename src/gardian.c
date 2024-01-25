#include "../includes/philosophers.h"
/*
 * Role: Keep an eye on all philosophers. To check if
 * - they're dying
 * - or full.
 * routine for the threads gardian
 */

int starving(t_philo *philo, t_begin *begin)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	unsigned long long currentTime = (unsigned long long )(time.tv_sec * 1000) + (unsigned long long )(time.tv_usec / 1000); // Convertir en millisecondes

	// Vérifier si le philosophe est en train de mourir de faim
	if (((unsigned long long )currentTime - philo->time_last_meal) > begin->time_to_eat)
	{
		return ERROR; // Le philosophe est en train de mourir de faim
	}

	return SUCCESS; // Le philosophe est en sécurité
}

//void	*keep_an_eye(void *arg)
////(t_philo *philo, t_begin *begin)
//{
//	t_philo 	*current;
//	int 		philos;
//	int 		all_lunch_eaten;
//	pthread_mutex_t m_lunch_eaten;
//
//	all_lunch_eaten = 0;
//	philos = 1;
//	current = philo;
//	while(1)
//	{
//		if (all_lunch_eaten == begin->nb_philo)
//			printf("stop_diner here\n");
//		while (philos <= begin->nb_philo) // check le statut de chaque philo
//		{
//			if((starving(current, philo)) == ERROR)
//			{
//				printf("someone is dead here\n");;// arrete tout
//				return (NULL);
//			}
//			pthread_mutex_lock(&m_lunch_eaten);// definir le mutex
//			if (current->ticket_repas == begin->nb_lunch)// check pour 1 si fini manger
//				all_lunch_eaten++;
//			pthread_mutex_unlock(&m_lunch_eaten);
//			philos++;
//		}
//	}
//
//}

void *keep_an_eye(void *arg)
{
	t_eye_arg *eye_arg = (t_eye_arg *)arg;  // Cast de void* à t_eye_arg*
	t_philo *philo;
	int philos;
	int all_lunch_eaten;
	pthread_mutex_t m_lunch_eaten;

	all_lunch_eaten = 0;
	philos = 0;  // Commencer à 0 si les indices commencent à 0
	philo = eye_arg->philo;
	t_begin *begin = eye_arg->begin;

	while (1)
	{
		if (all_lunch_eaten == begin->nb_philo)
		{
			printf("stop_diner here\n");
			break; // Sortir de la boucle si le dîner est terminé
		}
		while (philos < begin->nb_philo)
		{ // Assurer que les indices sont corrects
			if (starving(philo, begin) == ERROR)
			{
				printf("someone is dead here\n");
				return (NULL); // Arrêter le thread si un philosophe est mort
			}
			pthread_mutex_lock(&m_lunch_eaten); // Utiliser le bon mutex
			if (philo[philos].ticket_repas == begin->nb_lunch) // Vérifier si philosophe a fini de manger
				all_lunch_eaten++;
			pthread_mutex_unlock(&m_lunch_eaten);
			philos++;
		}
		philos = 0; // Réinitialiser le compteur pour le prochain tour de la boucle
	}

	free(eye_arg); // Libérer la mémoire allouée pour eye_arg
	return NULL;
}
