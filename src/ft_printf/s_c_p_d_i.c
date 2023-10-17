/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_c_p_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:59:53 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/25 15:37:36 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libftprintf.h"
#include "../../includes/ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		count += write (1, &s[i], 1);
		i++;
	}
	return (count);
}

int	ft_pointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += write (1, "0x0", 3);
	else
	{
		count += write(1, "0x", 2);
		ft_to_hex(ptr, 'p');
		count += (count_base_sixteen(ptr));
	}
	return (count);
}

int	ft_nbrlen(long number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		i = 1;
		number *= -1;
	}
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = ft_nbrlen(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
	return (count);
}
