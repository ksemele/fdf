/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:55:32 by cghael            #+#    #+#             */
/*   Updated: 2020/02/13 12:55:38 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** --------------------------- Macros \ Static ---------------------------------
*/

# define USAGE			"usage: ./fdf target_file\n"
# define MALLOC_ERROR	"malloc can't allocate memory"
# define CODE_ERROR		-1
# define MEM_SIZE		64
# define STEP_TURN		16

/*
** -------------------------------- COLORS -------------------------------------
*/

# define BACKGROUND		0x222222
# define CYBER			0x9B1F6A
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define TEXT_COLOR		0x9B2F6A

/*
** -------------------------- External Headers ---------------------------------
*/

/*
** for errno.h evaluates man intro(2)
*/

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include "keys.h"

/*
** ------------------------- Structures Definition -----------------------------
*/

typedef struct		s_color_step
{
	int				step;
	double			red_step;
	double			green_step;
	double			blue_step;
}					t_color_step;

typedef struct		s_color
{
	char			alpha : 8;
	char			red : 8;
	char			green : 8;
	char			blue : 8;
}					t_color;

typedef union		u_color_point
{
	t_color			color;
	int				int_color;
}					t_color_point;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	double			x_w;
	double			y_w;
	double			z_w;
	double			x_d;
	double			y_d;
	double			z_d;
	double			radius;
	double			angle;
	int				color;
	t_color_point	buff;
	t_color_step	color_step;
}					t_point;

typedef struct		s_map
{
	t_point			*px;
	int				len_x;
	int				len_y;
	int				total_points;
	t_point			center;
	double			angle;
	int				angle_count;
	int				iso;
	int				revers_draw;
}					t_map;

typedef struct		s_mouse
{
	char			is_pressed;
	int				previous_x;
	int				previous_y;
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_menu_ptr;
	char			*pixels;
	char			*pixels_menu;
	int				color;
	int				light;
	int				pressed;
	int				mouse_pressed;
	double			angle_x;
	double			angle_y;
	double			scale_z;
	double			scale;
	int				slide;
	int				win_x;
	int				win_y;
	int				win_menu_x;
	int				win_menu_y;
	int				bpp;
	int				width;
	int				endian;
	int				width_menu;
	t_map			map;
	t_mouse			mouse;
}					t_mlx;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_check_args(int argc, char **argv, t_mlx *mlx);
//void				ft_check_line_points(char *line, t_mlx *mlx);
//int					ft_increase_point_size(t_mlx *mlx);
void				ft_error_print(char *str, t_mlx *mlx);
t_mlx				*ft_create_t_mlx(void);
void				ft_read_points_to_struct(char **argv, t_mlx *mlx);
void				ft_write_double(t_mlx *mlx);
void				ft_turn_coords(t_mlx *mlx);
int					ft_atoi_base(const char *str, int base);
float				ft_fabsf(float i);
float				ft_fisbigger(float a, float b);
void				ft_scale_points(t_mlx *mlx);

/*
** ------------------------------ Image funcs ----------------------------------
*/

void				ft_center_point(t_mlx *mlx);
void				ft_coords_to_center(t_mlx *mlx);
void				ft_scale_z(t_mlx *mlx);
void				ft_img_isometric(t_mlx *mlx);
void				ft_img_isometric2(t_mlx *mlx);
void				ft_img_isometric3(t_mlx *mlx);
void				ft_draw_background(t_mlx *mlx);
void				ft_draw_img_line(t_point start, t_point end, t_mlx *mlx);
void				ft_draw_img_wireframe(t_mlx mlx);
void				ft_draw_img_menu(t_mlx *mlx);
void				ft_draw_img_menu_strings(t_mlx *mlx);
void				ft_draw_img_all(t_mlx *mlx);

/*
** ---------------------------- Pixel_put funcs --------------------------------
*/

void				ft_isometric(t_point *point, t_mlx *mlx);
void				ft_draw_line(t_point start, t_point end, t_mlx *mlx);
void				ft_draw_wireframe(t_mlx mlx);

/*
** --------------------------- Keyboard Controls -------------------------------
*/

void				ft_controls(t_mlx *mlx);
int					ft_deal_key(int key, t_mlx *mlx);
void				ft_move_scale(t_mlx *mlx);
void				ft_move_xy_keys(t_mlx *mlx);
void				ft_move_z_keys(t_mlx *mlx);
void				ft_do_isometric(t_mlx *mlx);
void				ft_light_control(t_mlx *mlx);
void				ft_turning(t_mlx *mlx);

#endif
