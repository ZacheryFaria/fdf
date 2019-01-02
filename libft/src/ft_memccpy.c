/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:32:21 by zfaria            #+#    #+#             */
/*   Updated: 2018/11/30 13:22:11 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		if (*ptr2 == (unsigned char)c)
		{
			*ptr = *ptr2;
			ptr++;
			return (ptr++);
		}
		*ptr = *ptr2;
		ptr++;
		ptr2++;
	}
	return (NULL);
}
