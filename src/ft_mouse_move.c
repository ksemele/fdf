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

static void		ft_mouse_slide_x(t_mlx *mlx)
{
	if (mlx->mouse.x > mlx->mouse.previous_x)
	{
		mlx->map.center.x_d += SLIDE;
	}
	if (mlx->mouse.x < mlx->mouse.previous_x)
	{
		mlx->map.center.x_d -= SLIDE;
	}
}

static void		ft_mouse_slide_y(t_mlx *mlx)
{
	if (mlx->mouse.y > mlx->mouse.previous_y)
	{
		mlx->map.center.y_d += SLIDE;
	}
	if (mlx->mouse.y < mlx->mouse.previous_y)
	{
		mlx->map.center.y_d -= SLIDE;
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
		ft_mouse_slide_x(mlx);
		ft_mouse_slide_y(mlx);
	}
	return (0);
}
