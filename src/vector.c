/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 10:33:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/03 15:08:27 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_v2d		*new_vec(int x, int y)
{
	t_v2d	*v2d;

	if ((v2d = malloc(sizeof(t_v2d))) == NULL)
		return (NULL);
	v2d->x = x;
	v2d->y = y;
	return (v2d);
}
