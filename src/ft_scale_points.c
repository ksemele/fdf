/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:58:52 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/03 11:58:52 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_scale_points(t_mlx *mlx)
{
	int		i;
	double	tmp;

	i = 0;
	if (mlx->scale > 0)
	{
		while (i < mlx->map.total_points)
		{
//			mlx->map.px[i].z_w *= mlx->scale;
//			if (round(mlx->map.px[i].z_w) == 0)
//				mlx->map.px[i].z_w = mlx->map.px[i].z_w * mlx->scale + mlx->map.px[i].z;
			mlx->map.px[i].z_w = (double)mlx->map.px[i].z * mlx->scale;
			mlx->map.px[i].y_w = (double)mlx->map.px[i].y * mlx->scale;
			mlx->map.px[i].x_w = (double)mlx->map.px[i].x * mlx->scale;
			i++;
		}
	}
//	else if (mlx->scale < 0)
//	{
//		while (i < mlx->map.total_points)
//		{
////			tmp = mlx->map.px[i].y_w;
////			mlx->map.px[i].z_w /= mlx->scale;
////			if (round(mlx->map.px[i].z_w) == 0)
////				mlx->map.px[i].z_w = (mlx->map.px[i].z_w / mlx->scale) + mlx->map.px[i].z;
//			mlx->map.px[i].z_w = mlx->map.px[i].z / mlx->scale;
//			mlx->map.px[i].y_w = mlx->map.px[i].y / mlx->scale;
//			mlx->map.px[i].x_w = mlx->map.px[i].x / mlx->scale;
////			mlx->map.px[i].z_w = mlx->map.px[i].y_w;
//			i++;
//		}
//	}
//	ft_write_double(mlx);
}
