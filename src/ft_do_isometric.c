/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_isometric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:42:57 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 15:42:58 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_do_isometric(t_mlx *mlx)
{
	if (mlx->pressed == NUM_1)
	{
		if (mlx->map.angle < 0)
			mlx->map.angle += 2 * M_PI;
		mlx->angle_x = M_PI / 6;
		mlx->map.iso = 1;
	}
	else if (mlx->pressed == NUM_2)
	{
		mlx->angle_x = M_PI / 4;
		mlx->map.iso = 2;
	}
	else if (mlx->pressed == NUM_0)
	{
		if (mlx->map.angle < 0)
			mlx->map.angle += 2 * M_PI;
		mlx->map.iso = 0;
	}
	if (mlx->map.iso == 1)
		ft_img_isometric(mlx);
	else if (mlx->map.iso == 2)
		ft_img_isometric2(mlx);
	else if (mlx->map.iso == 0)
		ft_img_isometric3(mlx);
}
