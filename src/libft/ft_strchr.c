/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:30:24 by angnguye          #+#    #+#             */
/*   Updated: 2022/12/07 22:16:40 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	carac;
	char			*str;

	i = 0;
	carac = (unsigned char)c;
	str = (char *)s;
	while (str[i] && str[i] != carac)
		i++;
	if (str[i] == carac)
		return (&str[i]);
	else
		return (NULL);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	const char s[] = "hello la compagnie";
	int c = 'a';
	printf("results %s\n",ft_strchr(s, c));

}
*/
