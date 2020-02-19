/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wireframe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:34:21 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/19 14:34:22 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_wireframe(t_mlx mlx_s)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y <= mlx_s.map.len_y)
	{
		while (x <= (mlx_s.map.len_x * mlx_s.map.len_y))
		{
			if (mlx_s.map.point[x].y == mlx_s.map.point[x + 1].y)
			{
				ft_draw_line(mlx_s.map.point[x],
							 mlx_s.map.point[x + 1], &mlx_s);
			}
			if (mlx_s.map.point[x].x == mlx_s.map.point[x + mlx_s.map.len_x].x)
			{
				ft_draw_line(mlx_s.map.point[x], \
						mlx_s.map.point[x + mlx_s.map.len_x], &mlx_s);
			}
			x++;
		}
		y++;
	}
}
