/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 09:41:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/31 11:36:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <math.h>

typedef struct	s_proj
{
	double		deltax;
	double		deltay;
	double		deltaz;
}				t_proj;

typedef struct	s_image
{
	void		*img;
	int			*ptr;
	int			bpp;
	int			wid;
	int			end;
}				t_image;

typedef struct	s_coor
{
	int		x;
	int		y;
	double	z;
	int		color;
}				t_coor;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
	int			width;
	int			height;
	t_list		*points;
	int			mapwid;
	int			maphei;
	t_proj		*proj;
	t_coor		*origin;
	double		zoom;
	t_coor		**pbuf;
	t_coor		mouse_p;
	t_coor		mouse_c;
	int			update;
	int			rotate;
	int			max_height;
}				t_mlx;

typedef	struct	s_args
{
	int			start;
	t_mlx		*mlx;
}				t_args;

# define PI 3.14159265359
# define ISO_TRUE (t_proj){0.523599, 0.523599, 0.523599}
# define ISO_21 (t_proj){0.463733, 0.463733, 0.463733}
# define DEFAULT_PROJ ISO_TRUE

int				event_key(int keycode, void *param);
int				event_close(void);
int				event_mouse(int x, int y, void *ptr);
int				fdf_loop(void *ptr);
int				event_mouse_pressed(int keycode, int x, int y, void *ptr);
int				event_mouse_released(int keycode, int x, int y, void *ptr);

t_image			*image_new(t_mlx *mlx);
void			image_set_pixel(t_mlx *mlx, t_coor *vec, int color);
void			image_plot_line(t_mlx *mlx, t_coor v1, t_coor v2, t_coor orig);
int				get_light(int start, int end, double percent);

t_coor			*new_coor(int x, int y, int z, int color);

void			rotate_x(t_coor *point, double thetacos, double thetasin);
void			rotate_y(t_coor *point, double thetacos, double thetasin);
void			rotate_z(t_coor *point, double thetacos, double thetasin);

# define COOR2(x,y) new_coor(x, y, 0, 0)

t_list			*read_file(char *str, int *len);
char			*basename(char *s);

void			plot_map(t_mlx *mlx);
void			redraw(t_mlx *mlx);
void			startup_threads(t_mlx *mlx);

void			*die(char *str);

#endif
