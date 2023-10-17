/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:39:37 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/18 13:04:47 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	carac;
	char			*str;

	i = ft_strlen(s);
	carac = (unsigned char)c;
	str = (char *)s;
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	while (i >= 0)
	{
		if (str[i] == carac)
			return (&str[i]);
		else
			i--;
	}
	return (0);
}
