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


static void		ft_draw_img_wireframe_rev(t_mlx mlx)
{
	int		x;
	int		y;
	int		next_x_y;
	int		tmp;

	y = mlx.map.len_y - 1;
	x = mlx.map.total_points - 1;
	tmp = 0;
//	ft_draw_background(&mlx);
//	ft_coords_to_center(&mlx);
	while (y >= 0)
	{
		while (tmp <= mlx.map.total_points)// && x - mlx.map.len_x >= 0)
		{
			next_x_y = x - mlx.map.len_x;
			if (x > 0 && mlx.map.px[x].y == mlx.map.px[x - 1].y)
			{
				ft_draw_img_line(mlx.map.px[x], mlx.map.px[x - 1], &mlx);
			}
			if (x - mlx.map.len_x >= 0 && mlx.map.px[x].x == mlx.map.px[next_x_y].x)
				ft_draw_img_line(mlx.map.px[x], mlx.map.px[next_x_y], &mlx);
			x--;
			tmp++;
		}
		y--;
	}
}

static void		ft_draw_img_wireframe_direct(t_mlx mlx)
{
	int		x;
	int		y;
	int		next_x_y;

	y = 0;
	x = 0;
//	ft_draw_background(&mlx);
//	ft_coords_to_center(&mlx);
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
				ft_draw_img_line(mlx.map.px[x], mlx.map.px[next_x_y], &mlx);
			x++;
		}
		y++;
	}
}

void		ft_draw_img_wireframe(t_mlx mlx)
{
	ft_draw_background(&mlx);
	ft_coords_to_center(&mlx);
	if (mlx.map.revers_draw)
		ft_draw_img_wireframe_rev(mlx);
	else
		ft_draw_img_wireframe_direct(mlx);

}
