/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:29:40 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/01 14:38:12 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*rev;
	int		i;
	int		last;

	last = ft_strlen(s) - 1;
	rev = ft_strnew(ft_strlen(s));
	if (rev)
	{
		i = 0;
		while (i <= last)
		{
			rev[i] = s[last - i];
			i++;
		}
		rev[i] = 0;
		return (rev);
	}
	return (NULL);
}
