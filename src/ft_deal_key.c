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
	if (mlx->pressed == NUM_PLUS)//TODO not work (
	{
		mlx->scale += 20;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x += 0.1;
		mlx->angle_y -= 0.1;
	}
	if (mlx->pressed == NUM_MINUS)//TODO not work (
	{
		mlx->scale += 20;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x -= 0.1;
		mlx->angle_y += 0.1;
	}
	if (mlx->pressed == 83)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//		mlx->angle_x -= 0.8;
//		mlx->angle_y += 0.8;
		ft_img_isometric(mlx);
	}
	if (mlx->pressed == 84)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->angle_x -= 0.5;
		mlx->angle_y += 0.5;
		ft_img_isometric(mlx);
	}
	ft_draw_img_wireframe(*mlx);
	if (mlx->pressed == SPACE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
		ft_draw_background(mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 50, 50);
	return (0);
}
