/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:54:37 by angnguye          #+#    #+#             */
/*   Updated: 2022/12/07 21:40:34 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		i++;
		number *= -1;
	}
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

static char	*ft_putnumber(char *str, long number, int len)
{
	while (number > 0)
	{
			str[len] = number % 10 + '0';
			number = number / 10;
			len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	num;
	int		nbrlen;

	num = n;
	nbrlen = ft_nbrlen(num);
	ptr = (char *)malloc(sizeof(char) * (nbrlen + 1));
	if (!ptr)
		return (0);
	ptr[nbrlen] = '\0';
	if (num == 0)
		ptr[0] = '0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = num * -1;
	}
	ptr = ft_putnumber(ptr, num, --nbrlen);
	return (ptr);
}
