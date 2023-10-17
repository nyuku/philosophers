/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:26:12 by angnguye          #+#    #+#             */
/*   Updated: 2022/12/08 16:42:57 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *restrict dest, char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char dest[] = "";
	char source[] = "bateau";
	size_t size = 3;

	size_t resultat = ft_strlcpy(dest, source, size);
	size_t result = strlcpy(dest, source, size);

	printf("ma fonction : %zu\n",resultat);
	printf("results %zu\n",result);
}
*/
