/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:26:45 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/01 13:30:12 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (s1 && s2)
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str)
		{
			str = ft_strcpy((char *)str, (char *)s1);
			str = ft_strcat((char *)str, (char *)s2);
			return (str);
		}
	}
	return (NULL);
}
