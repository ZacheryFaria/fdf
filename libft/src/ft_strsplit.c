/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 10:13:44 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 17:49:11 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int count;
	int newword;

	count = 0;
	newword = 1;
	while (*s)
	{
		if (*s == c)
			newword = 1;
		else if (newword)
		{
			newword = 0;
			count++;
		}
		s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**res;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = word_length(s, c);
			res[i] = ft_strsub(s, 0, word_length(s, c));
			res[i++][len] = 0;
			s += len;
		}
	}
	res[i] = NULL;
	return (res);
}
