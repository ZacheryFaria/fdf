/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/27 14:36:38 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"
#include "colors.h"

void	die(int type)
{
	if (type == NO_FILE)
		ft_putendl("No such file.");
	exit(0);
}

void	process_args(int argc, char **argv)
{
	argv++;
	if (argc < 2)
	{
		ft_putendl("usage: ./fdf <file> [proj]");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	
	process_args(argc, argv);
	mlx = malloc(sizeof(t_mlx));
	mlx->height = 600;
	mlx->width = 800;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "FDF");
	mlx_key_hook(mlx->win, &event_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, event_close, mlx);
	mlx->img = image_new(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
