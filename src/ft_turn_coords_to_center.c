/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_coords_to_center.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:17:56 by cghael            #+#    #+#             */
/*   Updated: 2020/03/02 14:17:57 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_turn_coords_to_center(t_mlx *mlx)
{
	double	delta_x;
	double	delta_y;
	int		i;
	double	prev_x;
	double	prev_y;

	i = 1;
	delta_x = sin(mlx->map.angle) * mlx->map.a_o;
	prev_x = mlx->map.px[0].x_d;
	mlx->map.px[0].x_d = round(mlx->map.center.x_d + delta_x);
	prev_x = mlx->map.px[0].x_d - prev_x;
	delta_y = cos(mlx->map.angle) * mlx->map.a_o;
	prev_y = mlx->map.px[0].y_d;
	mlx->map.px[0].y_d = round(mlx->map.center.y_d + delta_y);
	prev_y = mlx->map.px[0].y_d - prev_y;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_d += prev_x;
		mlx->map.px[i].y_d += prev_y;
		i++;
	}
}
