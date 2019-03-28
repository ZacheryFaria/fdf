/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 09:41:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 11:46:59 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>

typedef struct	s_image
{
	void		*img;
	int			*ptr;
	int			bpp;
	int			wid;
	int			end;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
	int			width;
	int			height;
}				t_mlx;

typedef struct	s_coor
{
	int x;
	int y;
	int z;
	int color;
}				t_coor;

int				event_key(int keycode, void *param);
int				event_close(void);

t_image			*image_new(t_mlx *mlx);
void			image_set_pixel(t_mlx *mlx, t_coor *vec, int color);
void			image_plot_line(t_mlx *mlx, t_coor *v1, t_coor *v2, int c);

t_coor			*new_coor(int x, int y, int z, int color);

#define COOR2(x,y) new_coor(x, y, 0, 0)

t_list			*read_file(char *str, int *len);

void			freev(void *v, ...);
void			plot_map(t_mlx *mlx, t_list *points, int width);

#endif
