/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:07:20 by cghael            #+#    #+#             */
/*   Updated: 2020/03/02 13:07:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_center_point(t_mlx *mlx)
{
	double	cathet_op;
	double	cathet_ad;

	mlx->map.center.x_d = (double)mlx->win_x / 2;
	mlx->map.center.y_d = (double)mlx->win_y / 2;
	mlx->map.center.color = WHITE;
//	mlx->map.center.z_d =
	cathet_op = fabs((double)mlx->map.px[0].x_d + \
			(double)(mlx->map.px[0].x_d - \
			mlx->map.px[mlx->map.total_points - 1].x_d) / 2);
	cathet_ad = fabs(mlx->map.px[0].y_d + \
			(double)(mlx->map.px[0].y_d - \
			mlx->map.px[mlx->map.total_points - 1].y_d) / 2);
	mlx->map.a_o = sqrt(pow(cathet_op, 2) + pow(cathet_ad, 2));
	mlx->map.angle = asin(cathet_op / mlx->map.a_o) + M_PI;
}