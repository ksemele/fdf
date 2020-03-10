/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:51:07 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 15:51:09 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_turn_iso2(t_mlx *mlx, double	angle_slide)
{
	int i;

	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		i = 0;
		while (i < 15)
		{
			if (mlx->map.angle <= -M_PI / 4)
				mlx->map.angle = 3 * (M_PI / 4);
			mlx->map.angle -= angle_slide;
			i++;
		}
	}
	else if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->map.angle <= -M_PI / 4)
			mlx->map.angle = 3 * (M_PI / 4);
		mlx->map.angle -= angle_slide;
	}
}

static void	ft_turn_iso1(t_mlx *mlx, double	angle_slide)
{
	int i;

	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->map.angle >= M_PI / 4)
			mlx->map.angle = 3 * -(M_PI / 4);
		mlx->map.angle += angle_slide;
	}
	else if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		i = 0;
		while (i < 15)
		{
			if (mlx->map.angle >= M_PI / 4)
				mlx->map.angle = 3 * -(M_PI / 4);
			mlx->map.angle += angle_slide;
			i++;
		}
	}
}

void		ft_turning(t_mlx *mlx)
{
	double	angle_slide;

	angle_slide = M_PI / 16;
	if (mlx->map.iso == 1 || mlx->map.iso == 0)
	{
//		if (mlx->map.angle < 0)
//			mlx->map.angle += 2 * M_PI;
		ft_turn_iso1(mlx, angle_slide);
	}
	else if (mlx->map.iso == 2)
		ft_turn_iso2(mlx, angle_slide);
//	if (mlx->pressed == NUM_9)
//	{
//		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//
//		if (mlx->map.angle >= M_PI / 4)
//			mlx->map.angle = 3 * -(M_PI / 4);
//		mlx->map.angle += angle_slide;
//	}
//	else if (mlx->pressed == NUM_7)
//	{
//		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//
//		int i = 0;
//		while (i < 15)
//		{
//			if (mlx->map.angle >= M_PI / 4)
//				mlx->map.angle = 3 * -(M_PI / 4);
//			mlx->map.angle += angle_slide;
//			i++;
//		}
//	}
	ft_printf("ISO_ %d\tcount %d\tangle [%f]\n", mlx->map.iso,mlx->map.angle_count, mlx->map.angle);//TODO
	ft_turn_coords(mlx);
}
