/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 12:58:46 by zfaria           ###   ########.fr       */
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
	t_list	*list;
	
	process_args(argc, argv);
	list = read_file(argv[1]);

	char *str = "0 0 0 0 0 0";
	ft_putnbr(ft_arrlen((void **)ft_strsplit(str, ' ')));
	ft_putchar('\n');
	ft_putarr(ft_strsplit(str, ' '), ' ');

	mlx = malloc(sizeof(t_mlx));
	mlx->height = 400;
	mlx->width = 600;
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
	image_plot_line(mlx, vector_make_2d(200, 200), vector_make_2d(200, 300), RED);
	image_plot_line(mlx, vector_make_2d(300, 200), vector_make_2d(300, 300), RED);
	image_plot_line(mlx, vector_make_2d(200, 200), vector_make_2d(300, 200), RED);
	image_plot_line(mlx, vector_make_2d(200, 300), vector_make_2d(300, 300), RED);
	image_plot_line(mlx, vector_make_2d(200, 200), vector_make_2d(250, 150), RED);
	image_plot_line(mlx, vector_make_2d(300, 200), vector_make_2d(250, 150), RED);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
}
