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
#include "mlx.h"

/*
** ------------------------- Structures Definition -----------------------------
*/

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_map
{
	t_point			*point;
	int				length_x;
	int				length_y;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_addr;
	int				color;
	int				pressed;
	t_map			map;
}					t_mlx;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void				ft_check_args(int argc, char **argv);
void				ft_error_print(char *str);
t_mlx				*ft_create_t_mlx(void);

#endif //FDF_H
