/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:37 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/18 12:51:45 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	char	*str;
	int		signe;

	i = 0;
	str = (char *)nptr;
	res = 0;
	signe = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (signe * res);
}

/*
#include<stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0;
    const char  str [] = " -82 06";
    printf("resultat : %i\n", atoi(str));
    printf("ma fonction : %i\n", ft_atoi(str));

}
*/
