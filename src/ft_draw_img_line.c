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

	if ((int)point->x_d <= mlx->win_x && point->y_d >= 0 && (int)point->y_d <= mlx->win_y)//TODO px->y_d >(>=) 0 ?
	{
		i = ((int)point->x_d * mlx->bpp / 8) + ((int)point->y_d * mlx->width);
		mlx->pixels[i] = point->color;
		mlx->pixels[++i] = point->color >> 8;
		mlx->pixels[++i] = point->color >> 16;
	}
//	int		*pixel;
//
//	pixel = (int *)(mlx->pixels);
//	i = 0;
//	while (i <= mlx->win_x * mlx->win_y)
//	{
//		pixel[i] = BACKGROUND;
//		i++;
//	}
}

void			ft_draw_img_line(t_point start, t_point end, t_mlx *mlx)
{
	float		x_step;
	float		y_step;
	float		max;

	ft_isometric(&start, mlx);
	ft_isometric(&end, mlx);
	x_step = end.x_d - start.x_d;
	y_step = end.y_d - start.y_d;
	max = fmax(fabs(x_step), fabs(y_step)) + 100;//TODO to double all
	x_step /= max;
	y_step /= max;
	while((int)(end.x_d - start.x_d) || (int)(end.y_d - start.y_d))
	{
//		start.color = CYBER ;
//		end.color = CYBER ;
//		start.color += (int)(end.color / max);//todo how change colors?
		if((int)start.x_d >= mlx->map.len_x && (int)start.y_d >= mlx->map.len_y)//todo think about it
		{
			ft_draw_img_pixel(mlx, &start);
			ft_draw_img_pixel(mlx, &end);
		}
		start.x_d += x_step;
		start.y_d += y_step;
	}
}