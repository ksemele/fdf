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

static void	ft_turn_iso(t_mlx *mlx)
{
	if (mlx->pressed == NUM_9)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle_count++;
	}
	else if (mlx->pressed == NUM_7)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->map.angle_count--;
	}
	if (mlx->map.angle_count == 0)
		mlx->map.angle = 0;
	else
		mlx->map.angle = (2 * M_PI / 32) * mlx->map.angle_count;
}

void		ft_turning(t_mlx *mlx)
{
	ft_turn_iso(mlx);
	if (mlx->map.iso == 1 || mlx->map.iso == 0)
	{
		if ((mlx->map.angle_count > 4 && mlx->map.angle_count <= 20) || \
				(mlx->map.angle_count <= -12 && mlx->map.angle_count > -28))
			mlx->map.revers_draw = 1;
		else
			mlx->map.revers_draw = 0;
	}
	else if (mlx->map.iso == 2)
	{
		if ((mlx->map.angle_count < -4 && mlx->map.angle_count >= -20) || \
				(mlx->map.angle_count >= 12 && mlx->map.angle_count < 28))
			mlx->map.revers_draw = 1;
		else
			mlx->map.revers_draw = 0;
	}
	if (mlx->map.angle_count >= 2 * STEP_TURN || mlx->map.angle_count <= 2 * -STEP_TURN)
	{
		mlx->map.angle = 0;
		mlx->map.angle_count = 0;
	}
	ft_printf("ISO_ %d\tcount %d\tangle [%f]\trevers [%d]\n", mlx->map.iso,mlx->map.angle_count, mlx->map.angle, mlx->map.revers_draw);//TODO
	ft_turn_coords(mlx);
}
