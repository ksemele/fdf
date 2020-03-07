/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_isometric3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:53:00 by cghael            #+#    #+#             */
/*   Updated: 2020/03/04 16:53:02 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_img_isometric3(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_w = \
				(double)mlx->map.px[i].x_w;
		mlx->map.px[i].y_w = \
				(double)mlx->map.px[i].y_w;
		i++;
	}
}
