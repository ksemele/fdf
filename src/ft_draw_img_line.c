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

static int		ft_bigger_three(int a, int b, int c)
{
	int	bigger;

	bigger = ft_isbigger(a, b);
	return (ft_isbigger(bigger, c));
}

static void		ft_gradient_step(t_point *start, t_point *end, t_mlx *mlx)
{
	t_color_point	start_p;
	t_color_point	end_p;
	int r;
	int g;
	int b;

	end_p.int_color = end->color;
	start_p.int_color = start->color;
	r = ft_abs(end_p.color.red - start_p.color.red);
	g = ft_abs(end_p.color.green - start_p.color.green);
	b = ft_abs(end_p.color.blue - start_p.color.blue);
	start->color_step.step = ft_bigger_three(r, g, b);
	start->color_step.red_step = (double)r / (double)start->color_step.step;
	start->color_step.green_step = (double)g / (double)start->color_step.step;
	start->color_step.blue_step = (double)b / (double)start->color_step.step;
}

static void		ft_draw_img_pixel(t_mlx *mlx, t_point *point)
{
	int			i;

	if ((int)point->x_d < mlx->win_x && (int)point->y_d >= 0 && \
		(int)point->y_d < (mlx->win_y - mlx->win_menu_y))
	{
		i = ((int)point->x_d * mlx->bpp / 8) + ((int)point->y_d * mlx->width);
		mlx->pixels[i + 0] = (char)(unsigned)(point->color & 0x0000ff);
		mlx->pixels[i + 1] = (char)(unsigned)((point->color & 0x00ff00) >> 8u);
		mlx->pixels[i + 2] = (char)(unsigned)((point->color & 0xff0000) >> 16u);
		mlx->pixels[i + 3] = (char)(unsigned)mlx->light;
	}
}

static void		ft_color_safty(t_point *start, t_point *end, t_mlx *mlx)
{
	if (mlx->map.revers_draw)
	{
		if (start->color >= end->color)
			end->color = start->color;
		else
			start->color = end->color;
	}
	else
	{
		if (start->color <= end->color)
			start->color = end->color;
		else
			end->color = start->color;
	}
}

static char	ft_add_color_step(double max, t_point *start, t_point *end, int mv)
{
	return (((start->color >> mv & 0xff) - (end->color >> mv & 0xff)) / max);
}

static void		ft_color_shift(double max, t_point *start, t_point *end)
{
	double	tmp_r;
	double	tmp_g;
	double	tmp_b;
	t_color_point	tmp;

	tmp.int_color = start->color;
	tmp.color.red += ft_add_color_step(max, start, end, 16);
	tmp.color.green += ft_add_color_step(max, start, end, 8);
	tmp.color.blue += ft_add_color_step(max, start, end, 0);
//	point->buff.int_color = point->color;
//	tmp_r = point->buff.color.red + point->color_step.red_step;
//	tmp_g = point->buff.color.green + point->color_step.green_step;
//	tmp_b = point->buff.color.blue + point->color_step.blue_step;
//	point->buff.color.red = tmp_r;
//	point->buff.color.green = tmp_g;
//	point->buff.color.blue = tmp_b;
//	point->color = point->buff.int_color;
	start->color = tmp.int_color;
}

//static void		ft_color_delta(t_mlx *mlx, t_point *point)
//{
//	point->color_step.red_step +=
//}

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
//	ft_color_safty(&start, &end, mlx);
//	ft_gradient_step(&start, &end, max, mlx);
	while ((int)(end.x_d - start.x_d) || (int)(end.y_d - start.y_d))
	{
		if ((int)start.x_d >= 0)
		{
			if (start.color != end.color)
				ft_color_shift(max, &start, &end);
			ft_draw_img_pixel(mlx, &start);
		}
		start.x_d += x_step;
		start.y_d += y_step;
//		if (start.color != end.color)
//			ft_color_shift(mlx, &start);
//		ft_color_delta(mlx, &start);
//		start.color += start.color_step;
	}
}
