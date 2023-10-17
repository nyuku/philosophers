/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:10:24 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/18 20:40:01 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*str1;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 == 0 || str2 == 0)
		return (NULL);
	ptr = malloc (sizeof(char) *(ft_strlen(str1) + ft_strlen(str2)+1));
	if (!ptr)
		return (0);
	while (str1[i])
	{
		ptr[i] = str1[i];
		i++;
	}
	while (str2[j])
		ptr[i++] = str2[j++];
	ptr[i] = '\0';
	return (ptr);
}
