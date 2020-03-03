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
	if (mlx->pressed == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
//		ft_free();//todo
		exit (0);
	}
	if (mlx->pressed == W || mlx->pressed == UP)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -50;
		ft_slide_y(mlx);
	}
	if (mlx->pressed == A || mlx->pressed == LEFT)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -50;
		ft_slide_x(mlx);
	}
	if (mlx->pressed == S|| mlx->pressed == DOWN)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 50;
		ft_slide_y(mlx);
	}
	if (mlx->pressed == D || mlx->pressed == RIGHT)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 50;
		ft_slide_x(mlx);
	}
	if (mlx->pressed == NUM_PLUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->scale = 2;
		ft_scale_points(mlx);
	}
	if (mlx->pressed == NUM_MINUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->scale = -2;
		ft_scale_points(mlx);
	}
	if (mlx->pressed == NUM_1)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x = M_PI / 3;
		mlx->angle_y = M_PI / 6;
		ft_img_isometric(mlx);
	}
	if (mlx->pressed == NUM_2)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x = M_PI / 4;
		mlx->angle_y = M_PI / 4;
		ft_img_isometric2(mlx);
	}
	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle -= M_PI / 16;
		mlx->map.sign = -1;
		ft_turn_coords(mlx);
	}
	if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle += M_PI / 16;
		mlx->map.sign = -1;
		ft_turn_coords(mlx);
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
	ft_draw_img_wireframe(*mlx);
	ft_draw_img_line(mlx->map.center, mlx->map.px[0], mlx); //todo del
	if (mlx->pressed == SPACE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
		ft_draw_background(mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}
