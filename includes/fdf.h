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

/*
** -------------------------------- COLORS -------------------------------------
*/

#define BACKGROUND		0x222222
#define CYBER			0x9B1F6A
#define BLACK			0x000000
#define WHITE			0xFFFFFF

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

typedef struct		s_color
{
	char			blue : 8;
	char			green : 8;
	char			red : 8;
	char			alpha : 8;
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
	double			x_d;
	double			y_d;
	double			z_d;
	int				color;
	t_color_point	color_u;
}					t_point;

typedef struct		s_map
{
	t_point			*px;
	int				len_x;
	int				len_y;
	int				total_points;
	t_point			center;
	double			angle;
	double			a_o;
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
	char			*pixels;
	int				color;
	int				light;
	int				pressed;
	double			angle_x;
	double			angle_y;
	int				scale_z;
	int				scale;
	int				slide;
	int				win_x;
	int				win_y;
	int				bpp;
	int				width;
	int				endian;
	t_map			map;
	t_mouse			mouse;
}					t_mlx;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_check_args(int argc, char **argv, t_mlx *mlx);
void				ft_check_line_points(char *line, t_mlx *mlx);
int					ft_increase_point_size(t_mlx *mlx);
void				ft_error_print(char *str, t_mlx *mlx);
t_mlx				*ft_create_t_mlx(void);
void				ft_read_points_to_struct(char **argv, t_mlx *mlx);
void				ft_write_double(t_mlx *mlx);
void				ft_turn_coords_to_center(t_mlx *mlx);
int					ft_atoi_base(const char *str, int base);
float				ft_fabsf(float i);
float				ft_fisbigger(float a, float b);

/*
** ------------------------------ Image funcs ----------------------------------
*/

void				ft_center_point(t_mlx *mlx);
void				ft_coords_to_center(t_mlx *mlx);
void				ft_img_isometric(t_mlx *mlx);
void				ft_img_isometric2(t_mlx *mlx);
void				ft_draw_background(t_mlx *mlx);
void				ft_draw_img_line(t_point start, t_point end, t_mlx *mlx);
void				ft_draw_img_wireframe(t_mlx mlx);

/*
** ---------------------------- Pixel_put funcs --------------------------------
*/

void				ft_isometric(t_point *point, t_mlx *mlx);
void				ft_draw_wireframe(t_mlx mlx);
void				ft_draw_line(t_point start, t_point end, t_mlx *mlx);

/*
** --------------------------- Keyboard Controls -------------------------------
*/

void				ft_controls(t_mlx *mlx);
int					ft_deal_key(int key, t_mlx *mlx);
void				ft_slide_x(t_mlx *mlx);
void				ft_slide_y(t_mlx *mlx);

/*
** ----------------------------- Mouse Controls --------------------------------
*/

int					ft_mouse_move(int x, int y, void *param);
int					ft_mouse_press(int key, int x, int y, void *param);
int					ft_mouse_release(int key, int x, int y, void *param);

#endif
