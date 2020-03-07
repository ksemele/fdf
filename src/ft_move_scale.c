//
// Created by Karina Semele on 05/03/2020.
//
#include "fdf.h"

void		ft_move_scale(t_mlx *mlx)
{
	if (mlx->pressed == NUM_PLUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->scale < 3)
			mlx->scale *= 1.1;
	}
	if (mlx->pressed == NUM_MINUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->scale > 0.1)
			mlx->scale /= 1.1;
	}
}