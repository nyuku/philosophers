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
# include <sys/time.h>


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
	pthread_t			id_philo;
	pthread_mutex_t 	mutex;
	int 				order;
	struct s_philo		*next;
	struct s_philo		*prev;
	int					ticket_repas;// decrementer a chaque repas
	unsigned long long	time_last_meal;
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
	unsigned long long			time_to_eat;
	int				time_to_sleep;
	int				nb_lunch;
	suseconds_t		start_time;
	pthread_t		id_gardian;

}			t_begin;

typedef	struct s_statut_all // pourrait etre des long? depend comment check_arg
{
	int				all_eaten;// vs nb_lunch
}			t_statut_all;

typedef struct s_eye_arg
{
	t_philo *philo;
	t_begin *begin;
}			t_eye_arg;


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
t_philo	*creat_list( int nb_philo, t_begin *begin);
void	print_nodes(t_philo **node);

char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
int	ft_nbrcount(int n);
size_t	ft_strlen(const char *str);
int	ft_atoi(const char *nptr);

//init
void		init(char **av, int ac, t_begin *begin);
void		mutex_utils(t_mutex *mutex_utils);
t_eye_arg	*init_arg_gardian(t_begin *begin, t_philo *philo);
//time
unsigned long long	time_dif(t_begin *begin);
void	time_start(t_begin *begin);

//guardian
void	*keep_an_eye(void *arg);

//main
void    wait_thread(t_philo	*philo, t_begin *begin);

#endif