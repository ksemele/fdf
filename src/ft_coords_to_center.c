/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords_to_center.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:54:34 by cghael            #+#    #+#             */
/*   Updated: 2020/03/02 11:54:36 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_coords_to_center(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_d = (mlx->map.px[i].x_w + mlx->map.center.x_d);
		mlx->map.px[i].y_d = (mlx->map.px[i].y_w + mlx->map.center.y_d) + mlx->win_menu_y / 2;
		i++;
	}
}
