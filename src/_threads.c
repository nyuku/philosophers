
#include "../includes/philosophers.h"

void* thread_routine(void *arg)
{
	(void)arg;
	printf("Bonjour du thread !\n");
	return NULL;
}

//cree les nodes au fur et a mesure et cree le thread avec le mutex
//int	init_philo( int nb_philo)
//{
////	int nb_philo; // aussi nb de threads
////
////	nb_philo = 0;
////	if (ac > 1)// devrait pas avoir besoin de check car ac sera obligatoirement min a 2
////		nb_philo = ac - 1;
////	else
////		return(ERROR);
//	while(nb_philo > 0)
//	{
//		if (creat_list(nb_philo) == ERROR)// cree node avec thread en mm temps avec leur mutex
//			return(ERROR);
//		nb_philo --;
//	}
//	return (SUCCESS);
//}
/*
 * comment creer une liste? donner une adresse du 1 er..?defini dans main
 */


//int main (int ac, char **av)
//{
//	t_philo *philo;
//
//	check_arg // devrait virer si pas de philo et pas argument
//
//	init_philo(philo, ac);
//}