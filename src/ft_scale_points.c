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

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].y_w = round(mlx->map.px[i].y_w * mlx->scale);
		mlx->map.px[i].x_w = round(mlx->map.px[i].x_w * mlx->scale);
		i++;
	}
}
