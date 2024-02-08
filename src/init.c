#include "../includes/philosophers.h"

void init_all(t_philo **philo, t_begin *begin, int argc, char **argv) 
{
	(void)argc;
	(void)argv;
	//init_arg_gardian(begin, *philo);
    init_philos(philo, begin->nb_philo, begin);
}

t_eye_arg	**init_threads(t_philo *philo, t_begin *begin, t_mutex *mutex)
{
	t_philo *current;
	current = philo;
	(void)begin;
	int bool_threads;

	t_eye_arg **eye_args = malloc(begin->nb_philo * sizeof(t_eye_arg*));
	if (!eye_args)
    {
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }
	int i = 0;
	while(current)
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
	 return eye_args;
}

void init_philos(t_philo **philo, int nb_philo, t_begin *begin) 
{
    // Utilisation de creat_list pour créer et initialiser la liste des philosophes
    *philo = creat_list(nb_philo, begin);

    // Vérification que la création a réussi
    if (*philo == NULL) {
        fprintf(stderr, "Erreur lors de la création de la liste des philosophes\n");
        // Ici, tu pourrais gérer l'erreur plus spécifiquement, par exemple en libérant des ressources allouées précédemment
        exit(EXIT_FAILURE);
    }
}


void init_value_start(char **av, int ac, t_begin *begin)
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

t_eye_arg *init_eye_arg(t_philo *philo, t_begin *begin, t_mutex *mutex) 
{
    t_eye_arg *eye_arg = (t_eye_arg *)malloc(sizeof(t_eye_arg));
    if (eye_arg == NULL) {
        perror("Failed to allocate t_eye_arg");
        exit(EXIT_FAILURE);
    }
    eye_arg->philo = philo;
    eye_arg->begin = begin;
    eye_arg->mutex = mutex;

    return eye_arg;
}

t_mutex *init_mutex(void) 
{
    t_mutex *mutex = (t_mutex *)malloc(sizeof(t_mutex));
    if (mutex == NULL) {
        perror("Failed to allocate t_mutex");
        exit(EXIT_FAILURE);
    }

    mutex->printing = malloc(sizeof(pthread_mutex_t));
    if (mutex->printing == NULL) {
        perror("Failed to allocate printing mutex");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_init(mutex->printing, NULL);

    mutex->time = malloc(sizeof(pthread_mutex_t));
    if (mutex->time == NULL) {
        perror("Failed to allocate time mutex");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_init(mutex->time, NULL);

    return mutex;
}
