/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:43:47 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/01 11:30:52 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <fdf.h>

void	*thread_draw(void *param)
{
	t_args	*args;
	t_mlx	*mlx;
	int		i;
	int		j;
	t_coor	orig;

	args = param;
	mlx = args->mlx;
	while (args->start < args->mlx->maphei)
	{
		j = 0;
		i = args->start;
		while (j < mlx->mapwid)
		{
			orig = mlx->pbuf[i][j];
			if (j < mlx->mapwid - 1)
				image_plot_line(mlx, orig, mlx->pbuf[i][j + 1], orig);
			if (i < mlx->maphei - 1)
				image_plot_line(mlx, orig, mlx->pbuf[i + 1][j], orig);
			j++;
		}
		args->start += mlx->threads;
	}
	free(param);
	return (0);
}

void	thread_join(pthread_t *threads, t_mlx *mlx)
{
	int i;
	int	*arg;

	i = 0;
	arg = malloc(sizeof(int));
	while (i < mlx->threads)
	{
		pthread_join(threads[i], (void **)arg);
		i++;
	}
	free(arg);
}

void	startup_threads(t_mlx *mlx)
{
	pthread_t	*threads;
	int			i;
	int			line_thread;
	int			line_extra;
	t_args		*args;

	i = 0;
	threads = malloc(sizeof(pthread_t) * mlx->threads);
	line_thread = mlx->maphei / mlx->threads;
	line_extra = mlx->maphei % mlx->threads;
	while (i < mlx->threads)
	{
		args = malloc(sizeof(t_args));
		args->mlx = mlx;
		args->start = i;
		pthread_create(&threads[i], NULL, thread_draw, args);
		i++;
	}
	thread_join(threads, mlx);
	free(threads);
}
