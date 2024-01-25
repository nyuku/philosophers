#include "../includes/philosophers.h"
void    wait_thread(t_philo	*philo, t_begin *begin)
{
	t_philo    *current;

	current = philo;
	while(current)
	{
		pthread_join(current->id_philo, NULL);
		current = current->next;
	}
	pthread_join(begin->id_gardian, NULL);
}

void    kill_mutex(t_philo	*philo)
{
	t_philo    *current;

	current = philo;
	while(current)
	{
		pthread_mutex_destroy(&current->mutex);
		current = current->next;
	}
}

void	table_for_one(char **av, int ac, t_begin *begin)
{
	unsigned long long timer;

	timer = time_dif(begin);
	if (ac > 1 && ft_atoi(av[1]) == 1)
	{
		printf("%llu\t1\t🥢 has taken a chopstick\t\n", timer);
		printf("\033[0;31m1\t1\t☠️ dead\t\t\033[0m\n");
		exit(0);
	}
	else
		return;

}

int main(int ac, char **av)
{

	t_begin begin;
	t_mutex *mutex;

//	begin = NULL;
	mutex = NULL;
	printf("Time(ms)\tPhilo\tAction\t\n");

	check_all_arg(av,ac);//return et stop si probleme, rien a free
	init(av,ac,&begin); //init valeur arg en struc,si se passe mal...liberer la struc
	time_start(&begin);
	table_for_one(av, ac, &begin);


	//mutex
	mutex_utils(mutex); // cree la liste des mutex pour print, check valeur ec

	//creat philo
	t_philo *philo = creat_list(begin.nb_philo,&begin);
	if (philo == NULL)// si un soucis lors de la creationde la liste, threads, mutex,etc
	{
		return(ERROR);
	}

	//gardian
	t_eye_arg *gardian_arg = init_arg_gardian(&begin, philo);
	if (gardian_arg != NULL) {
		if (pthread_create(&begin.id_gardian, NULL, keep_an_eye, (void *)gardian_arg) != 0)
		{
			free(gardian_arg);
		}
	}



	print_nodes(&philo);//test

	wait_thread(philo, &begin);
	kill_mutex(philo);
	return (SUCCESS);

}

//condition de fin -> mort philo -> time_to_die (temps passé sans mangé)
               //  -> si 5 arg, le nbre de repas atteint

