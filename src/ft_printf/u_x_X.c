/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_x_X.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:13:05 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/25 15:36:48 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

static void	ft_write(unsigned long long decima, char type, char c)
{
	if (c != 'p')
		decima = (unsigned int)decima;
	decima += type;
	write(1, &decima, 1);
}

int	count_base_sixteen(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	ft_putnbr_unsigned(n);
	count += ft_nbrlen(n);
	return (count);
}

int	ft_to_hex(unsigned long long decima, char c)
{
	int	count;

	count = 0;
	if (c == 'x' || c == 'X')
		decima = (unsigned int)decima;
	count += count_base_sixteen(decima);
	if (decima < 16)
	{
		if (decima >= 0 && decima < 10)
			ft_write(decima, '0', 0);
		else
		{
			if (c == 'x' || c == 'p')
				ft_write(decima, 'W', c);
			if (c == 'X')
				ft_write(decima, '7', 0);
		}
	}
	else
	{
		ft_to_hex(decima / 16, c);
		ft_to_hex(decima % 16, c);
	}
	return (count);
}
