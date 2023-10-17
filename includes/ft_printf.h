/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:14:26 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/25 15:32:10 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
/*
 * s_c_p_d_i.c
 */
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_pointer(unsigned long long ptr);
int		ft_nbrlen(long number);
int		ft_putnbr(int nb);
/*
 * u_x_X.c
 */
int		count_base_sixteen(unsigned long long n);
void	ft_putnbr_unsigned(unsigned int nb);
int		ft_print_unsigned(unsigned int n);
int		ft_to_hex(unsigned long long decima, char c);
/*
 * ft_printf.c
*/
int		ft_printf(const char *input, ...);
int		check_type(const char converter, va_list arg_ptr);

#endif
