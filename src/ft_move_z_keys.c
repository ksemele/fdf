/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_z_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:29:08 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 15:29:09 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move_z_keys(t_mlx *mlx)
{
	if (mlx->pressed == UP_NUM)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->scale_z < 10)
			mlx->scale_z += 1;
	}
	if (mlx->pressed == DOWN_NUM)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->scale_z >= -10)
			mlx->scale_z -= 1;
	}
	ft_scale_z(mlx);
}
