/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 10:33:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 11:45:17 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_v2d		*vector_make_2d(int x, int y)
{
	t_v2d	*v2d;

	if ((v2d = malloc(sizeof(t_v2d))) == NULL)
		return (NULL);
	v2d->x = x;
	v2d->y = y;
	return (v2d);
}
