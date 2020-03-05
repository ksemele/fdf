/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leathertube <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:33:24 by leathertu         #+#    #+#             */
/*   Updated: 2020/02/24 14:33:25 by leathertu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int				ft_deal_key(int key, t_mlx *mlx)
{
	ft_printf("key is: int [%1$d]\n", key);//нажали кнопку - зажгли пиксель
	mlx->pressed = key;
	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle += M_PI / 16;
	}
	if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle -= M_PI / 16;
	}
	ft_turn_coords(mlx);

	if (mlx->pressed == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
//		ft_free();//todo
		exit (0);
	}

	if (mlx->pressed == W || mlx->pressed == UP)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.center.y_d -= 50;
	}
	if (mlx->pressed == A || mlx->pressed == LEFT)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.center.x_d -= 50;
	}
	if (mlx->pressed == S|| mlx->pressed == DOWN)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.center.y_d += 50;
	}
	if (mlx->pressed == D || mlx->pressed == RIGHT)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.center.x_d += 50;
	}

	if (mlx->pressed == NUM_PLUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if ((mlx->scale < 50) && (mlx->scale >= 1))
		{
			mlx->scale += 1;
//			mlx->scale_z = mlx->scale / 2;
		}
		ft_scale_points(mlx);
	}
	if (mlx->pressed == NUM_MINUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->scale >= 2)
		{
			mlx->scale -= 1;
//			mlx->scale_z = mlx->scale / 2;
		}
		ft_scale_points(mlx);
	}

	if (mlx->pressed == NUM_1)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x = M_PI / 6;
		mlx->map.iso = 1;
	}
	if (mlx->pressed == NUM_2)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x = M_PI / 4;
		mlx->map.iso = 2;
	}
	if (mlx->pressed == NUM_3)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//		mlx->angle_x = M_PI / 4;
		mlx->map.iso = 3;
	}

	if (mlx->pressed == DIG_PLUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//		if(mlx->light <= 255)
			mlx->light += 10;
	}
	if (mlx->pressed == DIG_MINUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->light -= 10;
	}
	ft_draw_img_all(mlx);
	return (0);
}
