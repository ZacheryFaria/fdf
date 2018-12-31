/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 10:08:56 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/31 10:20:35 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int		event_key(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
		exit(0);
	}
	return (0);
}
