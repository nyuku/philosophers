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

//Couleur
#define COLOR_RESET "\033[0m"
#define COLOR_ROSE "\033[38;5;213m" // Rose n'est pas standard, utiliser un code approximatif
#define COLOR_LILAC "\033[38;5;183m" // Lilas, aussi approximatif
#define COLOR_VIOLET "\033[35m" // Violet standard
#define COLOR_GREEN "\033[32m" // Vert standard
#define COLOR_CYAN "\033[36m" // Cyan pour un bon contraste avec le reste

#define LEFT_FORK	"a pris la fourchette gauche"
#define	RIGHT_FORK	"a pris la fourchette droite"
#define	EAT 		"est en train de manger"
#define	SLEEP 		"fait une sieste"
#define	THINK 		"réflechi"
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
	int					stop;// status pour check par gardian
	int 				belly_full;
	pthread_mutex_t time_last_meal_mutex;
	
}						t_philo;

typedef struct 			s_mutex
{
	pthread_mutex_t		*printing;
	pthread_mutex_t		*time;
	pthread_mutex_t		*m_fatality;
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
	int					fatality;

}						t_begin;


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
void				free_mutex(t_mutex *mutex);

//threads
// void				*thread_routine(void *arg);
// int					init_philo(int ac);

//node
t_philo				*create_node(int nb_philo);
t_philo				*creat_list(int nb_philo, t_begin *begin);
void				print_nodes(t_philo **node);

void				free_philo_list(t_philo *philo);

//utils
char				*ft_strdup(const char *src);
char				*ft_itoa(int n);
int					ft_nbrcount(int n);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *nptr);
const char*			get_philo_color(int color_index);

//init
t_eye_arg 			**init_threads(t_philo *philo, t_begin *begin, t_mutex *mutex);
t_eye_arg			*init_eye_arg(t_philo *philo, t_begin *begin, t_mutex *mutex);
void				init_value_start(char **av, int ac, t_begin *begin);
t_mutex 			*init_mutex(void);
t_eye_arg			*init_arg_gardian(t_begin *begin, t_philo *philo);
void				init_philos(t_philo **philo, int nb_philo, t_begin *begin) ;
void				init_all(t_philo **philo, t_begin *begin, int argc, char **argv) ;
//time
unsigned long long	time_dif(unsigned long long int	current_time);
void				time_start(t_begin *begin);
unsigned long long int				get_current_time(void);

//guardian
void				*keep_an_eye(void *arg);

//main
void    			wait_thread(t_philo	*philo, t_begin *begin);

//routine
void				*routine(void *arg);
void				go_eat(t_begin *begin, t_philo *philo, t_mutex *mutex);
void				go_sleep(t_begin *begin,t_philo *philo, t_mutex *mutex);
void				go_think(t_begin *begin,t_philo *philo, t_mutex *mutex);
void	ph_log(int time, char *message, t_philo *philo, t_mutex *mutex);

#endif