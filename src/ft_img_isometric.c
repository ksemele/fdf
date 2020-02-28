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

static void		ft_write_double(int cur_point, t_mlx *mlx)
{
	mlx->map.px[cur_point].z_d = (double)mlx->map.px[cur_point].z;
	mlx->map.px[cur_point].y_d = (double)mlx->map.px[cur_point].y;
	mlx->map.px[cur_point].x_d = (double)mlx->map.px[cur_point].x;
}

void				ft_img_isometric(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		ft_write_double(i, mlx);
		i++;
	}
	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_d = \
				(mlx->map.px[i].x_d - mlx->map.px[i].y_d) * cos(mlx->angle_x);
		mlx->map.px[i].y_d = \
				(mlx->map.px[i].x_d + mlx->map.px[i].y_d) * \
					sin(mlx->angle_x) - mlx->map.px[i].z_d;
		i++;
	}
}
