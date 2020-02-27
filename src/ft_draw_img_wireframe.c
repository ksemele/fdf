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
	ft_draw_background(&mlx);
	while (y < mlx.map.len_y)
	{
//		ft_printf("total points %d\n", mlx.map.total_points);
//		ft_printf("x %d\tx+max %d\n", x, x + mlx.map.len_x);
		while (x <= mlx.map.total_points && x + 1 <= mlx.map.total_points)
		{
			if (mlx.map.px[x].y == mlx.map.px[x + 1].y && x >= 0 )
			{
//				if(mlx.map.px[x + 1].color && mlx.map.px[x].color)
					ft_draw_img_line(mlx.map.px[x],
									 mlx.map.px[x + 1], &mlx);
			}
			if (mlx.map.px[x].x == mlx.map.px[x + mlx.map.len_x].x && x + mlx.map.len_x <= mlx.map.total_points)
			{
//				if(mlx.map.px[x + mlx.map.len_x].color && mlx.map.px[x].color)
					ft_draw_img_line(mlx.map.px[x], \
						mlx.map.px[x + mlx.map.len_x], &mlx);
			}
			x++;
		}
		y++;
	}
}
