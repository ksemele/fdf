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
	int		i;
	double	tmp;

	i = 0;
	while (i < mlx->map.total_points)
	{
		tmp = mlx->map.px[i].x_w;
		mlx->map.px[i].x_w = \
				round(mlx->map.px[i].x_w * cos(mlx->angle_x) \
				- (double)mlx->map.px[i].y_w * cos(mlx->angle_x));
		mlx->map.px[i].y_w = \
				round(mlx->map.px[i].y_w * sin(mlx->angle_x) \
				+ tmp * sin(mlx->angle_x) - mlx->map.px[i].z_w);
		i++;
	}
}
