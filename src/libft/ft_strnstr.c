/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:40:26 by angnguye          #+#    #+#             */
/*   Updated: 2022/11/17 15:29:58 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s;
	size_t	n;

	s = 0;
	n = 0;
	if (!needle[0])
		return ((char *)&haystack[s]);
	if (!haystack[0] && len <= 0)
		return (NULL);
	while (haystack[s] && s < len)
	{
		while (haystack[s + n] == needle[n] && (needle[n]) && (s + n < len))
		{
			n++;
		}
		if (n == ft_strlen(needle))
			return ((char *)&haystack[s]);
		s++;
		n = 0;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char haystack[] = "hello patatee ca va";
	char needle[] = "tate";
	char empty[] = "";
	char emptyyy[] = "";
	size_t lon = -5;
	size_t len = 14;

	char *resultat = strnstr(empty, emptyyy, lon);
	char *mafonction = ft_strnstr(empty, emptyyy, lon);

	printf("la vrai: %s\n", resultat);
	printf("ma fonction: %s\n", mafonction);
}
*/