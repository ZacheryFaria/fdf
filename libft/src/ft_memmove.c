/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:12:41 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/01 13:04:20 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*osrc;
	unsigned char	*odst;

	odst = (unsigned char *)dst;
	osrc = (unsigned char *)src;
	if (src < dst)
		while (len--)
			odst[len] = osrc[len];
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
