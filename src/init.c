#include "../includes/philosophers.h"

void init(char **av, int ac, t_begin *begin)
{
	begin->nb_philo = ft_atoi(av[1]);
	begin->time_to_die = ft_atoi(av[2]);
	begin->time_to_eat = ft_atoi(av[3]);
	begin->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		begin->nb_lunch = ft_atoi(av[5]);
}

void	mutex_utils(t_mutex *mutex_utils)
{
	pthread_mutex_init(&mutex_utils->printing, NULL);
	pthread_mutex_init(&mutex_utils->time, NULL);
	//pthread_mutex_init(mutex_utils->index, NULL);
	//pthread_mutex_init(mutex_utils>dead, NULL);
	//pthread_mutex_init(mutex_utils->meal, NULL);
}