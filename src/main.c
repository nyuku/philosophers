//#include "../includes/philosophers.h"
//
//void	table_for_one(char **av, int ac)
//{
//	if (ac > 1 && ft_atoi(av[1]) == 1)
//	{
//		printf("0\t1\t🥄 has taken a fork\t\n");
//		printf("\033[0;31m1\t1\t☠️ dead\t\t\033[0m\n");
//	}
//	exit(0);
//}
//
//int main(int ac, char **av)
//{
//	(void)ac;
//	(void)av;
//	//qu'est ce qui se passe si m
////	int retour = 0;
////	t_begin *begin;
////	t_mutex *mutex;
////
////	begin = NULL;
////	mutex = NULL;
//	//check_all_arg(av,ac);//return et stop si probleme, rien a free
//	printf("Time\tPhilo\tAction\t\n");
////	table_for_one(av, ac);
////
////	init(av,ac,begin); //init valeur arg en struc,si se passe mal...liberer la struc
////
////	t_philo *philo = creat_list(begin->nb_philo);
////	if (philo == NULL)// si un soucis lors de la creationde la liste, threads, mutex,etc
////		//free struc
////	{
////		return(ERROR);
////	}
////	mutex_utils(mutex); // cree la liste des mutex pour print, check valeur ec
////	print_nodes(&philo);//test
//	return (SUCCESS);
//
//}

//condition de fin -> mort philo -> time_to_die (temps passé sans mangé)
//                 -> si 5 arg, le nbre de repas atteint

int main(int ac, char **av) {
	(void) ac;
	(void) av;
	return (0);
}