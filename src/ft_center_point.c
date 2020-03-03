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
	int		i;

	i = 0;
	mlx->map.center.x_d = round((double)fabs((double)(mlx->map.px[mlx->map.total_points - 1].x - mlx->map.px[0].x) / 2));
	mlx->map.center.y_d = round((double)fabs((double)(mlx->map.px[mlx->map.total_points - 1].y - mlx->map.px[0].y) / 2));
	mlx->map.center.color = WHITE;
//	mlx->map.center.z_d =
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x -= (int)(mlx->map.center.x_d);
		mlx->map.px[i].y -= (int)(mlx->map.center.y_d);
		i++;
	}
	mlx->map.center.x_d = round((double)mlx->win_x / 2);
	mlx->map.center.y_d = round((double)mlx->win_y / 2);
}