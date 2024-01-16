#include "../includes/philosophers.h"



int main(int ac, char **av)
{
	int retour = 0;

	check_all_arg(av,ac);
	int nb_philo;
	nb_philo = ft_atoi(av[1]);
	t_philo *philo = creat_list(nb_philo);
	print_nodes(&philo);
	return (retour);

}
