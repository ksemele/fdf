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

	if ((int)point->x_d < mlx->win_x && (int)point->y_d >= 0 && \
			(int)point->y_d < mlx->win_y)
	{
		i = ((int)point->x_d * mlx->bpp / 8) + ((int)point->y_d * mlx->width);
		mlx->pixels[i] = (char)point->color;
		mlx->pixels[i + 1] = (char)((unsigned)point->color >> 8u);
		mlx->pixels[i + 2] = (char)((unsigned)point->color >> 16u);
	}
}

void			ft_draw_img_line(t_point start, t_point end, t_mlx *mlx)
{
	double		x_step;
	double		y_step;
	double		max;

	x_step = end.x_d - start.x_d;
	y_step = end.y_d - start.y_d;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(end.x_d - start.x_d) || (int)(end.y_d - start.y_d))
	{
		if ((int)start.x_d >= 0)
			ft_draw_img_pixel(mlx, &start);
		start.x_d += x_step;
		start.y_d += y_step;
	}
	if ((int)start.x_d >= 0)
	{
		ft_draw_img_pixel(mlx, &start);
		ft_draw_img_pixel(mlx, &end);
	}
}
