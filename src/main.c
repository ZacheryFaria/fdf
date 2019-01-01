/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/01 13:18:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include "colors.h"
#include <stdio.h>

int	main(void)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->height = 400;
	mlx->width = 800;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "FDF");
	mlx_key_hook(mlx->win, &event_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, event_close, mlx);
	
	mlx->img = image_new(mlx);
	
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 600; j++)
		{
			image_set_pixel(mlx, vector_make_2d(j, i), WHITE);
		}
	}
	image_plot_line(mlx, vector_make_2d(0, 0), vector_make_2d(0, 100), RED);
	image_plot_line(mlx, vector_make_2d(100, 0), vector_make_2d(100, 100), RED);
	image_plot_line(mlx, vector_make_2d(0, 0), vector_make_2d(100, 0), RED);
	image_plot_line(mlx, vector_make_2d(0, 100), vector_make_2d(100, 100), RED);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
