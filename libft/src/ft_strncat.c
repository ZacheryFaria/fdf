/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:27:43 by zfaria            #+#    #+#             */
/*   Updated: 2018/11/28 20:04:38 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, char *src, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] && j < len)
	{
		dest[i++] = src[j++];
	}
	dest[i] = 0;
	return (dest);
}
