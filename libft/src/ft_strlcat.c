/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:33:14 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 16:59:37 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t i;
	size_t j;
	size_t destlen;
	size_t srclen;

	j = 0;
	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (len < destlen + 1)
		return (srclen + len);
	while (dest[i])
		i++;
	while (src[j] && i < len - 1)
		dest[i++] = src[j++];
	if (src[j] == '\0')
	{
		dest[i] = 0;
		return (i);
	}
	dest[i] = 0;
	return (destlen + srclen);
}
