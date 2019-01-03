/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 09:41:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/03 15:10:52 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>

enum			e_status
{
	NO_FILE,
	ARGC
};

typedef struct	s_image
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			sline;
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

typedef struct	s_v2d
{
	int x;
	int y;
}				t_v2d;

typedef struct	s_map_point
{
	int x;
	int y;
	int z;
	int color;
}				t_map_point;

int				event_key(int keycode, void *param);
int				event_close(void);

t_image			*image_new(t_mlx *mlx);
void			image_set_pixel(t_mlx *mlx, t_v2d *vec, int color);
void			image_plot_line(t_mlx *mlx, t_v2d *v1, t_v2d *v2, int c);

t_v2d			*new_vec(int x, int y);

t_map_point		*make_map_point(int x, int y, int z, int color);
t_map_point		**make_map_array(char *str, int y);

t_list			*read_file(char *str);
t_list			*read_coords(int fd);

void			die(int status);

void			printmap(t_map_point **map);

void			plot_lines(t_list *list, t_mlx *mlx);

#endif
