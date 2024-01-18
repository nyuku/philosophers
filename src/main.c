#include "../includes/philosophers.h"



int main(int ac, char **av)
{
	//qu'est ce qui se passe si m
	int retour = 0;
	t_begin *begin;
	t_mutex *mutex_utils;

	begin = NULL;
	mutex_utils = NULL;
	check_all_arg(av,ac);//return et stop si probleme, rien a free
	init(av,ac,begin); //init valeur arg en struc,si se passe mal...liberer la struc

	t_philo *philo = creat_list(begin->nb_philo);
	if (philo == NULL)// si un soucis lors de la creationde la liste, threads, mutex,etc
		//free struc

	init_mutex_utils(mutex_utils); // cree la liste des mutex pour print, check valeur ec
	print_nodes(&philo);//test
	return (retour);

}

//condition de fin -> mort philo -> time_to_die (temps passé sans mangé)
//                 -> si 5 arg, le nbre de repas atteint


//question: resultat toujours different, normal? juste geré au mieux ou laisser les threads tourné sans data race et tout..?
