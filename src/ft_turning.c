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

void		ft_turning(t_mlx *mlx)
{
	double	angle_slide;

	angle_slide = M_PI / 16;
	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//		mlx->map.angle_count += 1;
//		if (mlx->map.angle_count == 4)
//		{
//			mlx->map.angle = 0;
//			mlx->map.angle += 10 * (2 * M_PI - (angle_slide));
//			mlx->map.angle_count = -12;
//		}
		if (mlx->map.angle < M_PI / 4)
			mlx->map.angle += angle_slide;//4 ok
	}
	else if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->map.angle > -(M_PI - 5 * angle_slide))
			mlx->map.angle -= angle_slide;
//		mlx->map.angle_count -= 1;//-11 ok
//		if (mlx->map.angle_count <= -10)
//		{
//			mlx->map.angle -= M_PI;
//			mlx->map.angle_count = 0;
//		}
	}
	ft_printf("ISO_ %d\tcount %d\tangle [%f]\n", mlx->map.iso,mlx->map.angle_count, mlx->map.angle);//TODO
	ft_turn_coords(mlx);
}
