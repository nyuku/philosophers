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



typedef struct			s_philo
{
	pthread_t			id_philo;
	pthread_mutex_t 	*own_fork;
	pthread_mutex_t 	*left_fork;
	pthread_mutex_t		*right_fork;
	int 				order;
	struct s_philo		*next;
	struct s_philo		*prev;
	int					ticket_repas;// decrementer a chaque repas
	unsigned long long	time_last_meal;
	int					*stop;// status pour check par gardian
	int 				belly_full;
}						t_philo;

typedef struct 			s_mutex
{
	pthread_mutex_t		*printing;
	pthread_mutex_t		*time;
}						t_mutex;


typedef	struct 			s_begin // pourrait etre des long? depend comment check_arg
{
	int					nb_philo;
	int					time_to_die;
	unsigned long long	time_to_eat;
	int					time_to_sleep;
	int					nb_lunch;
	suseconds_t			start_time;
	pthread_t			id_gardian;

}						t_begin;

typedef	struct 			s_statut_all
{
	int					all_eaten;
}						t_statut_all;

typedef struct 			s_eye_arg
{
    t_philo				*philo;
    t_begin				*begin;
    t_mutex				*mutex;
} 						t_eye_arg;


/*◇───────────────────────────────────────────────────────────────◇*\
*	Prototypes
\*◇───────────────────────────────────────────────────────────────◇*/
int					check_if_number_str(char *str);
int					check_int_limit(char *av);
void				check_all_arg(char **av, int ac);
void				*routine_hello(void *arg);
int					threads_maker(void);
void				free_mutex(t_mutex *mutex, t_eye_arg *eye_arg);

//threads
void				*thread_routine(void *arg);
int					init_philo(int ac);

//node
t_philo				*create_node(int nb_philo);
t_philo				*creat_list(int nb_philo, t_begin *begin);
void				print_nodes(t_philo **node);
void				init_threads(t_philo *philo, t_begin *begin, t_eye_arg *eye_arg);
void				free_philo_list(t_philo *philo);

//utils
char				*ft_strdup(const char *src);
char				*ft_itoa(int n);
int					ft_nbrcount(int n);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *nptr);

//init
t_eye_arg			*init_eye_arg(t_philo *philo, t_begin *begin, t_mutex *mutex);
void				init_value_start(char **av, int ac, t_begin *begin);
t_mutex 			*init_mutex(void);
t_eye_arg			*init_arg_gardian(t_begin *begin, t_philo *philo);
void				init_philos(t_philo **philo, int nb_philo, t_begin *begin) ;
void				init_all(t_philo **philo, t_begin *begin, int argc, char **argv) ;
//time
unsigned long long	time_dif(t_begin *begin);
void				time_start(t_begin *begin);
long				get_current_time(void);

//guardian
void				*keep_an_eye(void *arg);
void				print_log(int time, char *message, int ph_id, pthread_mutex_t *print_mutex, t_philo *philo);
//main
void    			wait_thread(t_philo	*philo, t_begin *begin);

//routine
void				*routine(void *arg);
void				go_eat(t_begin *begin, t_philo *philo, t_mutex *mutex);
void				go_sleep(t_begin *begin, t_philo *philo, t_mutex *mutex);
void				go_think(t_begin *begin, t_philo *philo, t_mutex *mutex);

#endif