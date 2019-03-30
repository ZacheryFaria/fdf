/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/30 12:39:51 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"
#include "colors.h"

void	process_args(int argc, char **argv)
{
	argv++;
	if (argc < 2)
	{
		ft_putendl("usage: ./fdf <file> [proj]");
		exit(0);
	}
}

void	*die(char *str)
{
	ft_putstr(str);
	exit(1);
	return (0);
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

char	*basename(char *s)
{
	char	*p;
	int		i;

	if ((p = ft_strrchr(s, '/')) == 0)
		p = s;
	if (*p == '/')
		p++;
	i = 0;
	while (p[i])
	{
		if (ft_strncmp(p + i, ".fdf", 4) == 0)
		{
			p[i] = 0;
			break ;
		}
		i++;
	}
	return (p);
}

void	bind_event(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 17, event_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, event_close, mlx);
	mlx_hook(mlx->win, 6, 1L << 17, event_mouse, mlx);
	mlx_hook(mlx->win, 4, 1L << 17, event_mouse_pressed, mlx);
	mlx_hook(mlx->win, 5, 1L << 17, event_mouse_released, mlx);
	mlx_loop_hook(mlx->mlx, fdf_loop, mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*welcome;

	welcome = ft_strnew(ft_strlen(argv[1]) + 6);
	mlx = malloc(sizeof(t_mlx));
	mlx->points = read_file(argv[1], &mlx->mapwid);
	ft_strvcat(welcome, "FDF - ", basename(argv[1]), 0);
	mlx->maphei = ft_lstlen(mlx->points);
	mlx->pbuf = points_init(mlx);
	mlx->origin = COOR2(0, 0);
	mlx->zoom = 1;
	mlx->rotate = 0;
	mlx->update = 0;
	process_args(argc, argv);
	mlx->height = 800;
	mlx->width = 1024;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, welcome);
	mlx->img = image_new(mlx);
	mlx->proj = &DEFAULT_PROJ;
	bind_event(mlx);
	plot_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
