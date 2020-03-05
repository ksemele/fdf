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
	double		div;

	i = 0;
//	div = 1;
//	if (mlx->scale > 0)
//	{
//		div *= 1.1;
////		while (i < mlx->map.total_points)
////		{
////			mlx->map.px[i].y_d = round(mlx->map.px[i].y_d * 2);
////			mlx->map.px[i].x_d = round(mlx->map.px[i].x_d * 2);
////			i++;
////		}
//	}
//	if (mlx->scale < 0)
//	{
//		div /= 1.1;
////		while (i < mlx->map.total_points)
////		{
////			mlx->map.px[i].y_d = round(mlx->map.px[i].y_d / 2);
////			mlx->map.px[i].x_d = round(mlx->map.px[i].x_d / 2);
////			i++;
////		}
//	}
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].y_w = round(mlx->map.px[i].y_w * mlx->scale);
		mlx->map.px[i].x_w = round(mlx->map.px[i].x_w * mlx->scale);
		i++;
	}
}
