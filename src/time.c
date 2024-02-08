#include "../includes/philosophers.h"

long	get_current_time(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (time_now);
}

void	time_start(t_begin *begin)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	begin->start_time = (start.tv_sec * 1000 + start.tv_usec / 1000);
}

unsigned long long	time_dif(suseconds_t	current_time)
{
	long long int	result;
	long long int	temp_now;
	struct timeval	after;

	gettimeofday(&after, NULL);
	temp_now = (after.tv_sec * 1000 + after.tv_usec / 1000);
	result = temp_now - current_time;
	return (result);
}