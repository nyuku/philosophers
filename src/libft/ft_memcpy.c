/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:09:41 by angnguye          #+#    #+#             */
/*   Updated: 2022/12/08 16:35:26 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest,

const void *restrict source, size_t size)
{
	unsigned char	*pdest;
	unsigned char	*psource;
	size_t			i;

	pdest = (unsigned char *)dest;
	psource = (unsigned char *)source;
	i = 0;
	if (!dest && !source)
		return (0);
	while (size > 0)
	{
		pdest[i] = psource[i];
		i++;
		size--;
	}
	return (dest);
}
