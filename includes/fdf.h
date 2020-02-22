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

# define USAGE "usage: ./fdf target_file\n"
# define LEAK "8===3< < < "
# define MALLOC_ERROR "malloc can't allocate memory"
# define CODE_ERROR -1
# define MEM_SIZE 64

/*
** --------------------------------- KEYS --------------------------------------
*/

#define ESC 53
#define SPACE 49
#define W 13
#define A 0
#define S 1
#define D 2
#define N_W 91
#define N_A 86
#define N_S 87
#define N_D 88
#define NUM_PLUS 69
#define NUM_MINUS 78
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

/*
** -------------------------------- COLORS -------------------------------------
*/

#define BACKGROUND 0x222222
#define CYBER 0x9B1F6A
#define BLACK 0x000000
#define WHITE 0xFFFFFF


/*
** -------------------------- External Headers ---------------------------------
*/

/*
** for errno.h evaluates man intro(2)
*/

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

/*
** ------------------------- Structures Definition -----------------------------
*/

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	float			x_f;
	float			y_f;
	float			z_f;
	int				color;
}					t_point;

typedef struct		s_map
{
	t_point			*point;
	int				len_x;
	int				len_y;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*pixels;
	int				color;
	int				pressed;
	float			angle;
	int				scale;
	int				slide;
	int				win_x;
	int				win_y;
	int				bpp;
	int				width;
	int				endian;
	t_map			map;
}					t_mlx;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_check_args(int argc, char **argv, t_mlx *mlx);
void				ft_error_print(char *str, t_mlx *mlx);
t_mlx				*ft_create_t_mlx(void);
float				ft_fisbigger(float a, float b);
float				ft_fabs(float i);
void				ft_check_line_points(char *line, t_mlx *mlx);
int					ft_increase_point_size(t_mlx *mlx);
int					ft_atoi_base(const char *str, int base);
void				ft_write_points(const char *line, t_mlx *mlx);
void				ft_draw_background(t_mlx *mlx);
void				ft_draw_img_line(t_point start, t_point end, t_mlx *mlx);
void				ft_draw_img_wireframe(t_mlx mlx);
void				ft_draw_line(t_point start, t_point end, t_mlx *mlx);
void				ft_draw_wireframe(t_mlx mlx);
void				ft_isometric(t_point *point, t_mlx *mlx);
void				ft_slide_x(t_mlx *mlx);
void				ft_slide_y(t_mlx *mlx);

#endif
