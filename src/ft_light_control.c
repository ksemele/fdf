/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:47:46 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 15:47:47 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_light_control(t_mlx *mlx)
{
	if (mlx->pressed == DIG_PLUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->light += 10;
	}
	if (mlx->pressed == DIG_MINUS)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->light -= 10;
	}
}
