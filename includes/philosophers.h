#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <limits.h>


/*◇───────────────────────────────────────────────────────────────◇*\
*	Macro
\*◇───────────────────────────────────────────────────────────────◇*/
# define ERROR				1
# define SUCCESS			0

/*◇───────────────────────────────────────────────────────────────◇*\
*	Structure
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct s_philo
{
	pthread_t		id_philo;
	pthread_mutex_t mutex;
	int 			order;
	struct s_philo	*next;
	struct s_philo	*prev;
}			t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	printing;
	pthread_mutex_t	time;
}			t_mutex;


typedef	struct s_begin // pourrait etre des long? depend comment check_arg
{
	int				nb_philo;
	int				time_to_die;
	int 			time_to_eat;
	int				time_to_sleep;
	int				nb_lunch;
}			t_begin;
/*◇───────────────────────────────────────────────────────────────◇*\
*	Prototypes
\*◇───────────────────────────────────────────────────────────────◇*/
int		check_if_number_str(char *str);
int		check_int_limit(char *av);
void	check_all_arg(char **av, int ac);

void	*routine_hello(void *arg);
int		threads_maker(void);


//threads
void* thread_routine(void *arg);
int	init_philo(int ac);

//node
t_philo	*create_node(int nb_philo);
t_philo	*creat_list(int nb_philo);
void	print_nodes(t_philo **node);

char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
int	ft_nbrcount(int n);
size_t	ft_strlen(const char *str);
int	ft_atoi(const char *nptr);

//init
void init(char **av, int ac, t_begin *begin);

#endif