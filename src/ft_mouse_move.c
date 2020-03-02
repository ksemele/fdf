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

int			ft_mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx->mouse.previous_x = mlx->mouse.x;
	mlx->mouse.previous_y = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.is_pressed)
	{
//		mlx->camera->beta += (x - mlx->mouse.previous_x) * 0.002;
//		mlx->camera->alpha += (y - mlx->mouse.previous_y) * 0.002;
////		draw(mlx->map, mlx);
//ft_printf("m_ move %d\n", mlx->mouse.x);
//ft_printf("mousex = %d | %d\n", mlx->mouse.previous_x,mlx->mouse.x);
//ft_printf("x %d y %d\n", x, y);

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
	ft_draw_img_wireframe(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 50, 50);

	}
	return (0);
}