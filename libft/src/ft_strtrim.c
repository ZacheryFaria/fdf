/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 09:34:31 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 09:56:03 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		start;
	int		end;
	char	*bak;

	if (s)
	{
		if (ft_strlen(s) == 0)
			return ((char *)s);
		bak = ft_strrev((char *)s);
		if (!bak)
			return (NULL);
		start = 0;
		while (ft_isspace(s[start]))
			start++;
		end = 0;
		while (ft_isspace(bak[end]))
			end++;
		if (start + end > (int)ft_strlen(s))
			return (ft_strdup(""));
		bak = ft_strnew(ft_strlen(s) - start - end);
		bak = ft_strncpy(bak, (char *)s + start, ft_strlen(s) - start - end);
		return (bak);
	}
	return (NULL);
}
