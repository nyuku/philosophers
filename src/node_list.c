#include "../includes/philosophers.h"

// juste creer le slistes pas de threads encore
//gepeto, creationde la lliste, pas de threads mais au moins mutex
void free_philo_list(t_philo *philo) {
    t_philo *current = philo;
    t_philo *next;

    while (current != NULL) {
        next = current->next; // Sauvegarder le pointeur vers le prochain élément avant de libérer l'actuel
        free(current); // Libérer l'espace mémoire alloué pour le nœud actuel
        current = next; // Passer au nœud suivant
    }
}

t_philo *create_node(int order_philo) 
{
    t_philo *new_node = malloc(sizeof(t_philo));
    if (new_node == NULL) {
        printf("pas pu malloc le node\n");
        return (NULL);
    }

    new_node->order = order_philo;
	new_node->own_fork = malloc(sizeof(pthread_mutex_t)); // Allouer de la mémoire pour le mutex

    if (new_node->own_fork == NULL) 
	{
        printf("pas pu malloc le mutex\n");
        free(new_node); // Ne pas oublier de libérer new_node avant de retourner NULL
        return (NULL);
    }
    pthread_mutex_init(new_node->own_fork, NULL); // Initialiser le mutex pour chaque philosophe
	// new_node->left_fork = NULL; 
	// new_node->right_fork = NULL; 
    new_node->next = NULL;
    return (new_node);
}




t_philo *creat_list(int nb_philo, t_begin *begin) 
{
    int i = 1;
	(void)begin;
    t_philo *head = NULL;
    t_philo *before = NULL;
    //t_philo *first_philo = NULL;
	pthread_mutex_t *fist_fork;
	t_philo *new_philo;

    while (i <= nb_philo) 
	{
		new_philo = create_node(i);
		
        if (!head) 
		{
            head = new_philo;
			fist_fork = new_philo->own_fork;
            //first_philo = new_philo; // Sauvegarde le premier philosophe pour plus tard
        } 
		else 
		{
            before->right_fork = new_philo->own_fork; // La fourchette de droite est le mutex du philosophe suivant
            before->next = new_philo;
        }
		before = new_philo;
		new_philo->ticket_repas = begin->nb_lunch;
		new_philo->old_time_last_meal = 0;//test init
		new_philo->time_last_meal = 0;//test init
		new_philo->belly_full = 0;

        i++;
    }
	new_philo->right_fork = fist_fork;
    return head;
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
		printf("philo n*(%d) - id : %ld - Mutex = %p \n", current_node->order, (unsigned long)current_node->id_philo, (void*)&current_node->own_fork);
		current_node = current_node->next;
	}
}