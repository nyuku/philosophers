#include "../includes/philosophers.h"

int	check_if_number_str(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] == '0')
		return (ERROR);
	while (str[i] == '+' || str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		return (ERROR);
	if (str[i] == '\0')
		return (ERROR);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (ERROR);
	}
	return (SUCCESS);
}


int	check_int_limit(char *av)
{
	long l = atol(av);

	if (l < INT_MIN || l > INT_MAX)
		return (ERROR);
	return (SUCCESS);
}



void	check_all_arg(char **av, int ac) //exit tout seul si error
{
	int	i;

	i = 1;
	if (ac == 6)
	{
		while ( i < ac)
		{
			if (check_if_number_str(av[i]) == ERROR || check_int_limit(av[i]) == ERROR)
			{
				printf("mauvais arg\n");
				exit(0);
			}

			i++;
		}
		printf("gooooood\n");
	}
	else
	{

		printf("pas assez de arg\n1)nombre de philo\n2)time_to_die\n3)time to eat\n4)time to sleep\n5)nombre de repas\n");
		exit (0);
	}
}
