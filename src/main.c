/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:29:32 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/31 10:21:17 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>

int	main(void)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx, 600, 400, "FDF");
	mlx_key_hook(mlx->win, &event_key, mlx);
	mlx_loop(mlx);
}
