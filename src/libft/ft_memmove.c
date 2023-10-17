/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:15:56 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/10 19:42:53 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *s, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src;
	long			i;

	dest = (unsigned char *)dst;
	src = (unsigned char *)s;
	if (!dest && !src)
		return (0);
	if (src > dest)
		ft_memcpy(dst, src, len);
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			dest[i] = src[i];
			i--;
		}
	}
	return (dest);
}
