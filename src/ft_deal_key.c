/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leathertube <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:33:24 by leathertu         #+#    #+#             */
/*   Updated: 2020/02/24 14:33:25 by leathertu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_printf("key is: int [%1$d]\n", key); for debug
*/

int				ft_deal_key(int key, t_mlx *mlx)
{
	mlx->pressed = key;
	if (mlx->pressed == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free(mlx->map.px);
		exit(0);
	}
	ft_light_control(mlx);
	ft_move_xy_keys(mlx);
	ft_turning(mlx);
	ft_move_z_keys(mlx);
	ft_move_scale(mlx);
	ft_do_isometric(mlx);
	ft_draw_img_all(mlx);
	return (0);
}
