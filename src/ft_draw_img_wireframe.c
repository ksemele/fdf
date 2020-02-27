/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img_wireframe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:24:49 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/21 00:24:51 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_draw_img_wireframe(t_mlx mlx)
{
	int		x;
	int		y;
	int		next_x_y;

	y = 0;
	x = 0;
	ft_draw_background(&mlx);
	while (y < mlx.map.len_y)
	{
		while (x + 1 <= mlx.map.total_points && x < mlx.map.total_points)
		{
			next_x_y = x + mlx.map.len_x;
			if (mlx.map.px[x].y == mlx.map.px[x + 1].y && x >= 0)
			{
				ft_draw_img_line(mlx.map.px[x], mlx.map.px[x + 1], &mlx);
			}
			if (x + mlx.map.len_x < mlx.map.total_points && \
				mlx.map.px[x].x == mlx.map.px[next_x_y].x)
			{
				ft_draw_img_line(mlx.map.px[x], mlx.map.px[next_x_y], &mlx);
			}
			x++;
		}
		y++;
	}
}
