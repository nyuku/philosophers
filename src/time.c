#include "../includes/philosophers.h"

void	time_start(t_begin *begin)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	begin->start_time = (start.tv_sec * 1000 + start.tv_usec / 1000);
}

unsigned long long	time_dif(t_begin *begin)
{
	long long int	result;
	long long int	temp_now;
	struct timeval	after;

	gettimeofday(&after, NULL);
	temp_now = (after.tv_sec * 1000 + after.tv_usec / 1000);
	result = temp_now - begin->start_time;
	return (result);
}