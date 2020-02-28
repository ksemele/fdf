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
//		mlx->pixels[i] = (char)point->color;
//		mlx->pixels[++i] = (char)((unsigned)point->color >> 8u);
//		mlx->pixels[++i] = (char)((unsigned)point->color >> 16u);
		mlx->pixels[i] = 255; //red
		mlx->pixels[++i] = 255; //grn
		mlx->pixels[++i] = 255; //blu
		mlx->pixels[++i] = 255;//Alpha 0 max 255 min

	}
}

static void		ft_color_shift(t_point *point, int color_step)
{
	point->color_u.int_color = point->color;
	point->color_u.color.red & (char)color_step;
	point->color_u.color.green & (char)color_step >> 8;
	point->color_u.color.blue & (char)color_step >> 16;
	ft_printf("%d\t%b\t%b\t%b\n", point->color_u.int_color,
			point->color_u.color.red,
			point->color_u.color.green,
			point->color_u.color.blue);
	ft_printf("%d\t%c\t%c\t%c\n", point->color_u.int_color,
			point->color_u.color.red,
			point->color_u.color.green,
			point->color_u.color.blue);
	ft_printf("color %d\n", point->color);
	point->color = point->color_u.int_color;
	ft_printf("new color %d\n", point->color);
}

void			ft_draw_img_line(t_point start, t_point end, t_mlx *mlx)
{
	double x_step;
	double y_step;
	double max;
	int color_step;

	x_step = end.x_d - start.x_d;
	y_step = end.y_d - start.y_d;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	color_step = 0;
	if(start.color != end.color)
		color_step = (int)((double)(start.color - end.color) /
				fabs(fmax(x_step, y_step)));
//	if (start.z != end.z)
//		color_step = -color_step;
	while ((int)(end.x_d - start.x_d) || (int)(end.y_d - start.y_d))
	{

		if ((int)start.x_d >= 0)
		{
			if (start.color != end.color)
				ft_color_shift(&start, color_step);
			ft_draw_img_pixel(mlx, &start);
		}
		start.x_d += x_step;
		start.y_d += y_step;
	}
	if ((int)start.x_d >= 0)
	{
		ft_draw_img_pixel(mlx, &start);
		ft_draw_img_pixel(mlx, &end);
	}
}
