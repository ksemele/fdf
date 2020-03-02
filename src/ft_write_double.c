/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:13:55 by cghael            #+#    #+#             */
/*   Updated: 2020/03/02 13:13:56 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_write_double(t_mlx *mlx)
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