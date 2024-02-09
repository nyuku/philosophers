#include "../includes/philosophers.h"

void free_eye_args(t_eye_arg **eye_args, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(eye_args[i]);
    }
    free(eye_args);
}

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

void free_mutex(t_mutex *mutex) 
{
    if (mutex != NULL) 
	{
        // Détruire les mutex avant de libérer la mémoire
        if (mutex->printing != NULL) {
            pthread_mutex_destroy(mutex->printing);
            free(mutex->printing);
        }
        if (mutex->time != NULL) {
            pthread_mutex_destroy(mutex->time);
            free(mutex->time);
        }

        // Libérer la structure t_mutex elle-même
        free(mutex);
		mutex = NULL;
    }
}


void    kill_forks(t_philo	*philo)
{
	t_philo    *current;

	current = philo;
	while(current)
	{
		pthread_mutex_destroy(current->own_fork);
		free(philo->own_fork);
		current = current->next;
	}
}

void	table_for_one(char **av, int ac, t_begin *begin)
{
	unsigned long long timer;

	timer = time_dif(begin->start_time);
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
    t_philo *philo = NULL; // Liste des philosophes
	mutex = NULL;

	check_all_arg(av,ac);//return et stop si probleme, rien a free
	printf("Time(ms)   Philo\tAction\t\n");
	printf("--------------------------------------------------------\n");

	init_value_start(av, ac, &begin);
	// time_start(&begin);

	// table_for_one(av, ac, &begin);

	
	 //init
	mutex = init_mutex();
	init_all(&philo, &begin, ac, av);
	// t_eye_arg *eye_arg = init_eye_arg(philo, &begin, mutex);


	t_eye_arg	**eye_args = init_threads(philo, &begin, mutex);



	//end
	wait_thread(philo, &begin);
	kill_forks(philo);
	free_mutex(mutex);
	free_philo_list(philo);
	free_eye_args(eye_args, begin.nb_philo);
	return (SUCCESS);

}

//condition de fin -> mort philo -> time_to_die (temps passé sans mangé)
               //  -> si 5 arg, le nbre de repas atteint

