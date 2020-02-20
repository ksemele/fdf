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
** -------------------------- External Headers ---------------------------------
*/

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h> //man intro(2)
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
	char			*data_addr;
	int				color;
	int				pressed;
	float			angle;
	int				scale;
	int				window_x;
	int				window_y;
	t_map			map;
}					t_mlx;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_check_args(int argc, char **argv, t_mlx *mlx_s);
void				ft_error_print(char *str, t_mlx *mlx_s);
t_mlx				*ft_create_t_mlx(void);
float				ft_fisbigger(float a, float b);
float				ft_fmod(float i);
void				ft_check_line_points(char *line, t_mlx *mlx_s);
int					ft_increase_point_size(t_mlx *mlx_s);
int					ft_atoi_base(const char *str, int base);
void				ft_write_points(const char *line, t_mlx *mlx_s);
void				ft_draw_line(t_point start, t_point end, t_mlx *mlx_s);
void				ft_draw_wireframe(t_mlx mlx_s);
void				ft_isometric(t_point *point, t_mlx *mlx_s);

#endif //FDF_H
