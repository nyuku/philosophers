#include "../includes/philosophers.h"


t_philo	*create_node(int nb_philo)// cree un node avec toutes les info
{
	t_philo *new_node;
	int thread_create;

	new_node = malloc(sizeof(t_philo));
	if (new_node == NULL)
	{
		printf("pas pu malloc le node\n");
		return (NULL);
	}
	// creat philo
//	char *order_philo;
//	order_philo = ft_itoa(nb_philo);
	new_node->order = nb_philo;// str dup osef on a dit que cteait int
	//threadd
	thread_create = pthread_create(&new_node->id_philo, NULL, thread_routine, NULL);
	if (thread_create == ERROR)
	{
		printf ("pas pu creer le thread\n");
		return (NULL);
	}
	//pthread_mutex_init(&new_node->mutex, NULL);
	if (pthread_mutex_init(&new_node->mutex, NULL) != 0)
	{
		printf ("pas pu creer le mutex\n");
		free(new_node); // Libérez la mémoire en cas d'erreur
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

t_philo	*creat_list( int nb_philo, t_begin *begin)
{
	(void)begin;
	t_philo	*new_list;
	t_philo	*tail;
	t_philo	*new_node;
	int		i;

	i = 1;
	//current = philo;
	new_list = NULL;
	tail = NULL;
	printf ("nb de philooooo %d\n", nb_philo);
	while (i <= nb_philo)
	{
		new_node = create_node(i); // appelle notre fonction node solo
		if (new_node == NULL)
			return (NULL); // si mal malloc
		if (new_list == NULL) // tete de liste
			new_list = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		i++;
	}
	//on a cree les threads, maintenant le watcher
	return (new_list);
}

void	print_nodes(t_philo **node)
{
	t_philo	*current_node;

	current_node = *node;
	printf("Liste des philos :\n");
	if (current_node == NULL)
		printf("c'est vide\n");
	while (current_node != NULL)
	{
		printf("philo n*(%d) - id : %ld - Mutex = %p \n", current_node->order, (unsigned long)current_node->id_philo, (void*)&current_node->mutex);
		current_node = current_node->next;
	}
}