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

	y = 0;
	x = 0;
	int i = 0;//TODO d
	ft_draw_background(&mlx);
	while (y <= mlx.map.len_y)
	{
//		ft_printf("points %d\n", mlx.map.total_points);
		while (x <= mlx.map.total_points)
		{
			if (mlx.map.point[x].y == mlx.map.point[x + 1].y && x > 0 && x <= 800)
			{
				if(mlx.map.point[x + 1].color && mlx.map.point[x].color)
					ft_draw_img_line(mlx.map.point[x],
								 mlx.map.point[x + 1], &mlx);
				i++;//TODO d
			}
			if (mlx.map.point[x].x == mlx.map.point[x + mlx.map.len_x].x)
			{
				if(mlx.map.point[x + mlx.map.len_x].color && mlx.map.point[x].color)
					ft_draw_img_line(mlx.map.point[x], \
						mlx.map.point[x + mlx.map.len_x], &mlx);
				i++;//TODO d
			}
			x++;
		}
		y++;
	}
	ft_printf("draw %d lines\n", i);//TODO d
}
