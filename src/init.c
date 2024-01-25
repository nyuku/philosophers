#include "../includes/philosophers.h"

void init(char **av, int ac, t_begin *begin)
{
	begin->nb_philo = ft_atoi(av[1]);
	begin->time_to_die = ft_atoi(av[2]);
	begin->time_to_eat = ft_atoi(av[3]);
	begin->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		begin->nb_lunch = ft_atoi(av[5]);
	else
		begin->nb_lunch = -1; // on utilise la valeur dans la routine comme condition de fin, mettre un neg pour indiqué nada
}

void	mutex_utils(t_mutex *mutex_utils)
{
	pthread_mutex_init(&mutex_utils->printing, NULL);
	pthread_mutex_init(&mutex_utils->time, NULL);
	//pthread_mutex_init(mutex_utils->index, NULL);
	//pthread_mutex_init(mutex_utils>dead, NULL);
	//pthread_mutex_init(mutex_utils->meal, NULL);
}

t_eye_arg *init_arg_gardian(t_begin *begin, t_philo *philo)
{
	t_eye_arg *eye_arg = malloc(sizeof(t_eye_arg));
	if (eye_arg == NULL) {
		// Gérer l'erreur d'allocation de mémoire
		return NULL;
	}

	eye_arg->philo = philo;
	eye_arg->begin = begin;

	return (eye_arg);
}
