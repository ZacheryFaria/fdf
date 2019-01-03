/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:50:19 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/03 15:20:04 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include <libft.h>

#define paddingx 10
#define paddingy 10

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
			image_plot_line(mlx, new_vec(x * 10, y * 10), new_vec((x + 1) * 10, y * 10), RED);
			image_plot_line(mlx, new_vec(x * 10, y * 10), new_vec(x * 10, (y + 1) * 10), RED);
			x++;
		}
		y++;
		image_plot_line(mlx, new_vec(0, y * 10), new_vec(x * 10, y * 10), RED);
		image_plot_line(mlx, new_vec(x * 10, 0), new_vec(x * 10, y * 10), RED);
		list = list->next;
	}
}
