/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:12:52 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/20 16:12:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_img_pixel(t_mlx *mlx, t_point *point)
{
	int			i;

	if ((int)point->x_f < mlx->win_x && point->y_f >= 0 && (int)point->y_f < mlx->win_y)
	{
		i = ((int)point->x_f * mlx->bpp / 8) + ((int)point->y_f * mlx->size_line);
		mlx->pixels[i] = point->color;
		mlx->pixels[++i] = point->color >> 8;
		mlx->pixels[++i] = point->color >> 16;
	}
}



void			ft_draw_img_line(t_point start, t_point end, t_mlx *mlx)
{
	float		x_step;
	float		y_step;
	float		max;

	ft_isometric(&start, mlx);
	ft_isometric(&end, mlx);
	x_step = end.x_f - start.x_f;
	y_step = end.y_f - start.y_f;
	max = ft_isbigger(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(end.x_f - start.x_f) || (int)(end.y_f - start.y_f))
	{
		start.color = CYBER + 80000;
		end.color = CYBER + 80000;
//		start.color *= (int)(end.color / ft_isbigger(ft_fmod(x_step), ft_fmod(y_step)));//todo how change colors?
		if((int)start.x_f + 1 >= mlx->map.len_x && (int)start.y_f >= mlx->map.len_y)//todo think about it
			ft_draw_img_pixel(mlx, &start);
		start.x_f += x_step;
		start.y_f += y_step;
	}
}