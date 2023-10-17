/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:05:17 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/10 18:22:33 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a < 128)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
    int a = 0;
    //a = 50;
    a = 130;
    ft_isascii(a);
    printf( "resultat %d\n", ft_isascii(a));
}
*/
