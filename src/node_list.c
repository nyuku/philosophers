/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:01:48 by angela            #+#    #+#             */
/*   Updated: 2024/02/11 12:11:19 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_philo_list(t_philo *philo)
{
	t_philo	*current;
	t_philo	*next;

	current = philo;
	while (current != NULL)
	{
		next = current->next;
		pthread_mutex_destroy(&current->time_last_meal_mutex);
		free(current);
		current = next;
	}
}

t_philo	*create_node(int order_philo)
{
	t_philo	*new_node;

	new_node = malloc(sizeof(t_philo));
	if (new_node == NULL)
	{
		printf("pas pu malloc le node\n");
		return (NULL);
	}
	new_node->order = order_philo;
	new_node->own_fork = malloc(sizeof(pthread_mutex_t));
	if (new_node->own_fork == NULL)
	{
		printf("pas pu malloc le mutex\n");
		free(new_node);
		return (NULL);
	}
	pthread_mutex_init(new_node->own_fork, NULL);
	new_node->next = NULL;
	return (new_node);
}

t_philo	*creat_list(int nb_philo, t_begin *begin)
{
	int				i;
	t_philo			*head;
	t_philo			*before;
	t_philo			*new_philo;
	pthread_mutex_t	*fist_fork;

	i = 1;
	(void)begin;
	head = NULL;
	before = NULL;
	while (i <= nb_philo)
	{
		new_philo = create_node(i);
		if (!head)
		{
			head = new_philo;
			fist_fork = new_philo->own_fork;
		}
		else
		{
			before->right_fork = new_philo->own_fork;
			before->next = new_philo;
		}
		before = new_philo;
		new_philo->ticket_repas = begin->nb_lunch;
		new_philo->time_last_meal = 0;
		new_philo->belly_full = 0;
		new_philo->stop = 0;
		pthread_mutex_init(&new_philo->time_last_meal_mutex, NULL);
		i++;
	}
	new_philo->right_fork = fist_fork;
	return (head);
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
