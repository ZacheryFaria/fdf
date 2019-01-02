/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:48:03 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/01 11:50:06 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*new;
	size_t	i;

	new = malloc(size);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < size)
		new[i] = 0;
	return (new);
}
