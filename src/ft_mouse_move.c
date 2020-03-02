/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:49:19 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/02 10:49:20 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SLIDE 10

static void		ft_mouse_slide_x(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.x > mlx->mouse.previous_x)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = SLIDE;
		ft_slide_x(mlx);
	}
	if (mlx->mouse.x < mlx->mouse.previous_x)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -SLIDE;
		ft_slide_x(mlx);
	}
}

static void		ft_mouse_slide_y(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.y > mlx->mouse.previous_y)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = SLIDE;
		ft_slide_y(mlx);
	}
	if (mlx->mouse.y < mlx->mouse.previous_y)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -SLIDE;
		ft_slide_y(mlx);
	}
}

int				ft_mouse_move(int x, int y, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx->mouse.previous_x = mlx->mouse.x;
	mlx->mouse.previous_y = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.is_pressed)
	{
		ft_mouse_slide_x(x, y, mlx);
		ft_mouse_slide_y(x, y, mlx);
		ft_draw_img_wireframe(*mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 50, 50);
	}
	return (0);
}