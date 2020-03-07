/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:17:56 by cghael            #+#    #+#             */
/*   Updated: 2020/03/02 14:17:57 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_turn_coords(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_w = \
			round((double)mlx->map.px[i].x * cos(mlx->map.angle) - \
			(double)mlx->map.px[i].y * sin(mlx->map.angle));
		mlx->map.px[i].y_w = \
			round((double)(mlx->map.px[i].x) * sin(mlx->map.angle) + \
			(double)mlx->map.px[i].y * cos(mlx->map.angle));
		i++;
	}
}
