/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:38:00 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 20:05:50 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		exists;
	size_t	i;
	size_t	j;

	if (!*needle || haystack == needle || (!*haystack && !*needle))
		return ((char *)haystack);
	j = 0;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			exists = 1;
			i = -1;
			while (needle[++i])
			{
				if (haystack[i] != needle[i])
					exists = 0;
			}
			if (exists && j + i <= len)
				return ((char *)haystack);
		}
		j++;
		haystack++;
	}
	return (NULL);
}
