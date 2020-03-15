/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_xy_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:08:50 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 15:08:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move_xy_keys(t_mlx *mlx)
{
	if (mlx->pressed == W || mlx->pressed == UP)
	{
		mlx->map.center.y_d -= 10;
	}
	if (mlx->pressed == A || mlx->pressed == LEFT)
	{
		mlx->map.center.x_d -= 10;
	}
	if (mlx->pressed == S || mlx->pressed == DOWN)
	{
		mlx->map.center.y_d += 10;
	}
	if (mlx->pressed == D || mlx->pressed == RIGHT)
	{
		mlx->map.center.x_d += 10;
	}
}
