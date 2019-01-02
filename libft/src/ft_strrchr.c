/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:36:48 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 17:08:59 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last;

	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (c == 0 && s[i] == 0)
		return ((char *)s + i);
	else if (last >= 0)
		return ((char *)s + last);
	return (NULL);
}
