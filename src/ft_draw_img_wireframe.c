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
	int i = 0;
	ft_draw_background(&mlx);
	while (y <= mlx.map.len_y)
	{
		while (x <= (mlx.map.len_x * mlx.map.len_y))
		{
			if (mlx.map.point[x].y == mlx.map.point[x + 1].y)
			{
				ft_draw_img_line(mlx.map.point[x],
								 mlx.map.point[x + 1], &mlx);
				i++;
			}
			if (mlx.map.point[x].x == mlx.map.point[x + mlx.map.len_x].x)
			{
				ft_draw_img_line(mlx.map.point[x], \
						mlx.map.point[x + mlx.map.len_x], &mlx);
				i++;
			}//TODO work but not cut the sides!
//			if (x < mlx.map.len_x - 1)
//				ft_draw_img_line(mlx.map.point[x],
//							 mlx.map.point[x + 1], &mlx);
//			if (y < mlx.map.len_y - 1)
//				ft_draw_img_line(mlx.map.point[x], \
//						mlx.map.point[x + mlx.map.len_x], &mlx);
			x++;
		}
		y++;
	}
	ft_printf("draw %d lines\n", i);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
}
