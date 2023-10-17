/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:46:49 by angnguye          #+#    #+#             */
/*   Updated: 2022/12/07 21:41:08 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	len_word(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c, int index)
{
	int		len;
	int		i;
	char	*ptr;

	len = len_word(s, c, index);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[index];
		i++;
		index++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr;
	int		count_words;
	int		index;

	if (!s)
		return (0);
	count_words = count_word(s, c);
	ptr = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (0);
	i = 0;
	index = 0;
	while (i < count_words && s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0' && s[index] != c)
			ptr[i] = malloc_word(s, c, index);
		while (s[index] != c && s[index] != '\0')
			index++;
		i++;
		ptr[i] = 0;
	}
	return (ptr);
}
