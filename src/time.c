/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:12:42 by angela            #+#    #+#             */
/*   Updated: 2024/02/10 18:14:06 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_timer(void)
{
	struct timeval	time;
	int				t;

	t = 0;
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

void	time_start(t_begin *begin)
{
	begin->start_time = get_timer();
}

unsigned long long int	time_dif(unsigned long long int current_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - current_time) * 1000) + (time.tv_usec / 1000));
}
