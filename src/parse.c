/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:50:19 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/04 12:05:18 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include <libft.h>

#define pad 5

void	plot_lines(t_list *list, t_mlx *mlx)
{
	int		x;
	int		y;
	char	**str;

	y = 0;
	while (list)
	{
		str = ft_strsplit(list->content, ' ');
		x = 0;
		while (str[x + 1])
		{
			image_plot_line(mlx, new_vec(x * pad, y * pad), new_vec((x + 1) * pad, y * pad), RED);
			image_plot_line(mlx, new_vec(x * pad, y * pad), new_vec(x * pad, (y + 1) * pad), RED);
			x++;
		}
		y++;
		image_plot_line(mlx, new_vec(0, y * pad), new_vec(x * pad, y * pad), RED);
		image_plot_line(mlx, new_vec(x * pad, 0), new_vec(x * pad, y * pad), RED);
		list = list->next;
	}
}
