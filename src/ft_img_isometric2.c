/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_isometric2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:15:20 by cghael            #+#    #+#             */
/*   Updated: 2020/02/28 15:15:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_img_isometric2(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_w = \
				mlx->map.px[i].x_d + mlx->map.px[i].y_d * sin(mlx->angle_y);
		mlx->map.px[i].y_w = \
				mlx->map.px[i].y_d * sin(mlx->angle_y) - mlx->map.px[i].z_d;

//		mlx->map.px[i].x_w = mlx->map.px[i].x_w * cos(mlx->angle_x) - mlx->map.px[i].y_w * cos(mlx->angle_x);
//		mlx->map.px[i].y_w = mlx->map.px[i].y_w * sin(mlx->angle_x) - mlx->map.px[i].z_d;
		i++;
	}
}
