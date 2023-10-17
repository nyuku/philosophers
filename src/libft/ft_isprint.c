/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:08:10 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/10 18:23:11 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int a)
{
	if (a > 31 && a < 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
    int a = 0;
    //a = 32;
     a = 20;
    ft_isprint(a);
    printf("resultat %d\n", ft_isprint(a));
}
*/
