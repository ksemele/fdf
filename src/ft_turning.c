/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:51:07 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 15:51:09 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_turning(t_mlx *mlx)
{
	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle += M_PI / 16;
	}
	else if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle -= M_PI / 16;
	}
	ft_turn_coords(mlx);
}
