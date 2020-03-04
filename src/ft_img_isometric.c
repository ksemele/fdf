/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:51:55 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/28 11:51:57 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_img_isometric(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_w = (double)mlx->map.px[i].x * cos(mlx->angle_x) - (double)mlx->map.px[i].y * cos(mlx->angle_x);
		mlx->map.px[i].y_w = (double)mlx->map.px[i].y * sin(mlx->angle_x) + (double)mlx->map.px[i].x * sin(mlx->angle_x) - mlx->map.px[i].z;
		i++;
	}
}
