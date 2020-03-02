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

static void		ft_write_double(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].z_d = (double) mlx->map.px[i].z;
		mlx->map.px[i].y_d = (double) mlx->map.px[i].y;
		mlx->map.px[i].x_d = (double) mlx->map.px[i].x;
		i++;
	}
}

void				ft_img_isometric2(t_mlx *mlx)
{
	int i;

	i = 0;
	ft_write_double(mlx);
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_d = \
				mlx->map.px[i].x_d + mlx->map.px[i].y_d * sin(mlx->angle_y);
		mlx->map.px[i].y_d = \
				mlx->map.px[i].y_d * sin(mlx->angle_y) - mlx->map.px[i].z_d;
		i++;
	}
}