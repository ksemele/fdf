/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:13:37 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/07 16:13:38 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move_scale(t_mlx *mlx)
{
	if (mlx->pressed == NUM_PLUS)
	{
		if (mlx->scale < 3)
			mlx->scale *= 1.1;
	}
	if (mlx->pressed == NUM_MINUS)
	{
		if (mlx->scale > 0.1)
			mlx->scale /= 1.1;
	}
}
