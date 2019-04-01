/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 10:17:03 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"
#include "colors.h"

void	process_args(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		ft_putendl("usage: ./fdf <file>");
		exit(0);
	}
}

t_coor	**points_init(t_mlx *mlx)
{
	t_coor	**buf;
	int		i;

	buf = ft_memalloc(sizeof(buf) * mlx->maphei);
	i = 0;
	while (i < mlx->maphei)
	{
		buf[i] = ft_memalloc(sizeof(t_coor) * mlx->mapwid);
		i++;
	}
	return (buf);
}

void	bind_event(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 17, event_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, event_close, mlx);
	mlx_hook(mlx->win, 6, 1L << 17, event_mouse, mlx);
	mlx_hook(mlx->win, 4, 1L << 17, event_mouse_pressed, mlx);
	mlx_hook(mlx->win, 5, 1L << 17, event_mouse_released, mlx);
	mlx_loop_hook(mlx->mlx, fdf_loop, mlx);
	mlx->zoom = 30.0 / mlx->mapwid;
	mlx->proj = malloc(sizeof(t_proj));
}

void	find_biggest(t_mlx *mlx, int *num)
{
	int		i;
	int		j;
	t_list	*points;

	i = 0;
	*num = 0;
	points = mlx->points;
	while (points)
	{
		j = 0;
		while (j < mlx->mapwid)
		{
			if (*num < ((int *)points->content)[j])
			{
				*num = ((int *)points->content)[j];
			}
			j++;
		}
		i++;
		points = points->next;
	}
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*welcome;

	process_args(argc, argv);
	welcome = ft_strnew(ft_strlen(argv[1]) + 6);
	mlx = malloc(sizeof(t_mlx));
	mlx->points = read_file(argv[1], &mlx->mapwid);
	find_biggest(mlx, &mlx->max_height);
	ft_strvcat(welcome, "FDF - ", basename(argv[1]), 0);
	mlx->maphei = ft_lstlen(mlx->points);
	mlx->pbuf = points_init(mlx);
	mlx->origin = COOR2(0, 0);
	mlx->zoom = 1;
	mlx->rotate = 0;
	mlx->update = 0;
	mlx->height = 1080;
	mlx->width = 1920;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, welcome);
	mlx->img = image_new(mlx);
	bind_event(mlx);
	*mlx->proj = DEFAULT_PROJ;
	plot_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
