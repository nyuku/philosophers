#include "../includes/philosophers.h"

int get_timer(void)
{
	struct timeval	time;
	int t = 0;
	gettimeofday(&time, NULL);
	t = time.tv_sec;
	return (t);

}

unsigned long long int	get_current_time(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (time_now);
}

// void	time_start(t_begin *begin)
// {
// 	begin->start_time = get_current_time();;
// }
void	time_start(t_begin *begin)
{
	begin->start_time = get_timer();;
}


unsigned long long int time_dif(unsigned long long int current_time)
{
    // long long int temp_now = get_current_time(); // Utilise get_current_time pour obtenir le temps actuel en ms
    // long long int result = temp_now - current_time; // Calcule la différence en ms
    // return result;
	struct timeval	time;
	gettimeofday(&time, NULL);
	return (((time.tv_sec - current_time) * 1000) + (time.tv_usec / 1000));
}
