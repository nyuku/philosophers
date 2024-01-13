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
# define ERROR				0
# define SUCCESS			1

/*◇───────────────────────────────────────────────────────────────◇*\
*	Structure
\*◇───────────────────────────────────────────────────────────────◇*/

int	check_if_number_str(char *str);
int	check_int_limit(char *av);
void	check_all_arg(char **av, int ac);

void *routine_hello(void *arg);
int threads_maker(void);
#endif