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

void		ft_draw_img_wireframe(t_mlx mlx_s)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	int i = 0;
	ft_draw_background(&mlx_s);//TODO  WORKING! %)
	while (y <= mlx_s.map.len_y)
	{
		while (x <= (mlx_s.map.len_x * mlx_s.map.len_y))
		{
			if (mlx_s.map.point[x].y == mlx_s.map.point[x + 1].y)
			{
				ft_draw_img_line(mlx_s.map.point[x],
							 mlx_s.map.point[x + 1], &mlx_s);
				i++;
			}
			if (mlx_s.map.point[x].x == mlx_s.map.point[x + mlx_s.map.len_x].x)
			{
				ft_draw_img_line(mlx_s.map.point[x], \
						mlx_s.map.point[x + mlx_s.map.len_x], &mlx_s);
				i++;
			}
			x++;
		}
		y++;
	}
	ft_printf("draw %d lines\n", i);
	mlx_put_image_to_window(mlx_s.mlx_ptr, mlx_s.win_ptr, mlx_s.img_ptr, 0, 0);
}
