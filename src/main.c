/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:16:16 by angela            #+#    #+#             */
/*   Updated: 2024/02/11 11:21:27 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_eye_args(t_eye_arg **eye_args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(eye_args[i]);
		i++;
	}
	free(eye_args);
}
// void wait_thread(t_philo *philo, t_begin *begin) {
//     t_philo *current = philo;

//     while (current) {
//         printf("Joining thread for philo %d\n", current->order); // Debug print
//         if (pthread_join(current->id_philo, NULL) != 0) {
//             perror("pthread_join failed");
//         }
//         current = current->next;
//     }

//     printf("Joining gardian thread\n"); // Debug print
//     if (pthread_join(begin->id_gardian, NULL) != 0) {
//         perror("pthread_join for gardian failed");
//     }
// }

void	wait_thread(t_philo	*philo, t_begin *begin)
{
	t_philo	*current;

	current = philo;
	while (current)
	{
		pthread_join(current->id_philo, NULL);
		current = current->next;
	}
	pthread_join(begin->id_gardian, NULL);
}

void	free_mutex(t_mutex *mutex)
{
	if (mutex != NULL)
	{
        if (mutex->printing != NULL) 
		{
			pthread_mutex_destroy(mutex->printing);
            free(mutex->printing);
        }
        if (mutex->time != NULL) {
            pthread_mutex_destroy(mutex->time);
            free(mutex->time);
        }
		if (mutex->m_fatality != NULL)
		{
			pthread_mutex_destroy(mutex->m_fatality);
			free(mutex->m_fatality);

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
	while(current != NULL)
	{
		if (current->own_fork != NULL)
		{
			pthread_mutex_destroy(current->own_fork);
			free(current->own_fork);
		}
		pthread_mutex_destroy(&current->time_last_meal_mutex);
		
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
	mutex = init_mutex();
	init_all(&philo, &begin, ac, av);
	begin.fatality = 0;
	t_eye_arg	**eye_args = init_threads(philo, &begin, mutex);



	//end
	wait_thread(philo, &begin);
	printf("1\n");
	kill_forks(philo);
	printf("2\n");
	free_mutex(mutex);
	printf("3\n");
	free_philo_list(philo);
	printf("4\n");
	free_eye_args(eye_args, begin.nb_philo);
	return (SUCCESS);

}

//condition de fin -> mort philo -> time_to_die (temps passé sans mangé)
               //  -> si 5 arg, le nbre de repas atteint

