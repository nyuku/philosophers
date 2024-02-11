#include "../includes/philosophers.h"

void	init_all(t_philo **philo, t_begin *begin, int argc, char **argv) 
{
	(void)argc;
	(void)argv;
    init_philos(philo, begin->nb_philo, begin);
}

t_eye_arg	*init_arg_gardian(t_begin *begin, t_philo *philo)
{
	t_eye_arg	*eye_arg;

	eye_arg = malloc(sizeof(t_eye_arg));
	if (eye_arg == NULL)
    {
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }
	eye_arg->philo = philo;
	eye_arg->begin = begin;
	return (eye_arg);
}

t_eye_arg	**init_threads(t_philo *philo, t_begin *begin, t_mutex *mutex)
{
	int			i;
	t_philo		*current;
	int			bool_threads;
	t_eye_arg 	**eye_args;
	t_eye_arg	*keep_an_eye_arg;
	
	current = philo;
	(void)begin;
	eye_args = malloc(begin->nb_philo * sizeof(t_eye_arg*));
	if (!eye_args)
    {
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }
	i = 0;
	time_start(begin);
	//-------------------------------
	keep_an_eye_arg = init_arg_gardian(begin, philo);
	bool_threads = pthread_create(&begin->id_gardian, NULL, keep_an_eye, (void *)keep_an_eye_arg); // ici creation du philo et appe;ler la struc *arg
		if ( bool_threads == ERROR)
		{
			printf("pas pu creer le thread\n");
			exit(0);
		}
	//--------------------------------------------
	bool_threads = SUCCESS;
	while (current)
	{
		eye_args[i]  = init_eye_arg(current, begin, mutex);
		bool_threads = pthread_create(&current->id_philo, NULL, routine, (void *)eye_args[i]); // ici creation du philo et appe;ler la struc *arg
		if ( bool_threads == ERROR)
		{
			printf("pas pu creer le thread\n");
			exit(0);
		}
		current = current->next;
		i++;
	}
	 return (eye_args);
}

void	init_philos(t_philo **philo, int nb_philo, t_begin *begin) 
{
    // Utilisation de creat_list pour créer et initialiser la liste des philosophes
    *philo = creat_list(nb_philo, begin);

    // Vérification que la création a réussi
    if (*philo == NULL) 
	{
        fprintf(stderr, "Erreur lors de la création de la liste des philosophes\n");
        exit(EXIT_FAILURE);
    }
}


void	init_value_start(char **av, int ac, t_begin *begin)
{
	begin->nb_philo = ft_atoi(av[1]);
	begin->time_to_die = ft_atoi(av[2]);
	begin->time_to_eat = ft_atoi(av[3]);
	begin->time_to_sleep = ft_atoi(av[4]);
	// begin->fatality = 0;
	if (ac == 6)
		begin->nb_lunch = ft_atoi(av[5]);
	else
		begin->nb_lunch = -1; // on utilise la valeur dans la routine comme condition de fin, mettre un neg pour indiqué nada
}




t_eye_arg	*init_eye_arg(t_philo *philo, t_begin *begin, t_mutex *mutex) 
{
    t_eye_arg *eye_arg;
	
	eye_arg = (t_eye_arg *)malloc(sizeof(t_eye_arg));
    if (eye_arg == NULL) 
	{
        perror("Failed to allocate t_eye_arg");
        exit(EXIT_FAILURE);
    }
    eye_arg->philo = philo;
    eye_arg->begin = begin;
    eye_arg->mutex = mutex;

    return (eye_arg);
}

// t_mutex	*init_mutex(void) 
// {
//     t_mutex *mutex;
	
// 	mutex = (t_mutex *)malloc(sizeof(t_mutex));
//     if (mutex == NULL) 
// 	{
//         perror("Failed to allocate t_mutex");
//         exit(EXIT_FAILURE);
//     }

//     mutex->printing = malloc(sizeof(pthread_mutex_t));
//     if (mutex->printing == NULL) 
// 	{
//         perror("Failed to allocate printing mutex");
//         exit(EXIT_FAILURE);
//     }
//     pthread_mutex_init(mutex->printing, NULL);

//     mutex->time = malloc(sizeof(pthread_mutex_t));
//     if (mutex->time == NULL)
// 	{
//         perror("Failed to allocate time mutex");
//         exit(EXIT_FAILURE);
//     }
//     pthread_mutex_init(mutex->time, NULL);
	
// 	mutex->fatality = malloc(sizeof(pthread_mutex_t));
//     if (mutex->fatality == NULL) 
// 	{
//         perror("Failed to allocate fatality mutex");
//         exit(EXIT_FAILURE);
//     }
//     pthread_mutex_init(mutex->fatality, NULL);
//     return (mutex);
// }
t_mutex *init_mutex(void)
{
	t_mutex *mutex = malloc(sizeof(t_mutex));
	if (mutex == NULL)
	{
		perror("Failed to allocate memory for mutexes");
		exit(EXIT_FAILURE);
	}

	mutex->printing = malloc(sizeof(pthread_mutex_t));
	mutex->time = malloc(sizeof(pthread_mutex_t));
	mutex->m_fatality = malloc(sizeof(pthread_mutex_t));

	if (mutex->printing == NULL || mutex->time == NULL || mutex->m_fatality == NULL) 
	{
		perror("Failed to allocate memory for a mutex");
		// Nettoyage si nécessaire, puis sortie
		free(mutex->printing);
		free(mutex->time);
		free(mutex->m_fatality);
		free(mutex);
		exit(EXIT_FAILURE);
	}

	pthread_mutex_init(mutex->printing, NULL);
	pthread_mutex_init(mutex->time, NULL);
	pthread_mutex_init(mutex->m_fatality, NULL);

	return mutex;
}