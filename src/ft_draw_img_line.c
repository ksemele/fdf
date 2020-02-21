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

static void		ft_draw_img_pixel(t_mlx *mlx_s, t_point *point)
{
	int			i;

	if ((int)point->x_f < mlx_s->win_x && point->y_f >= 0 && (int)point->y_f < mlx_s->win_y)
	{
		i = ((int)point->x_f * mlx_s->bpp / 8) + ((int)point->y_f * mlx_s->size_line);
		mlx_s->pixels[i] = point->color;
		mlx_s->pixels[++i] = point->color >> 8;
		mlx_s->pixels[++i] = point->color >> 16;
	}
}



void			ft_draw_img_line(t_point start, t_point end, t_mlx *mlx_s)
{
	float		x_step;
	float		y_step;
	float		max;

	ft_isometric(&start, mlx_s);
	ft_isometric(&end, mlx_s);
	x_step = end.x_f - start.x_f;
	y_step = end.y_f - start.y_f;
	max = ft_fisbigger(ft_fmod(x_step), ft_fmod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(end.x_f - start.x_f) || (int)(end.y_f - start.y_f))
	{
		start.color = CYBER + 80000;
		end.color = CYBER + 80000;
//		start.color *= (int)(end.color / ft_isbigger(ft_fmod(x_step), ft_fmod(y_step)));//todo how change colors?
		ft_draw_img_pixel(mlx_s, &start);
		start.x_f += x_step;
		start.y_f += y_step;
//		ft_draw_img_pixel(mlx_s, &end);
//		end.x_f -= x_step;
//		end.y_f -= y_step;
	}
	mlx_put_image_to_window(mlx_s->mlx_ptr, mlx_s->win_ptr, mlx_s->img_ptr, 0, 0);
}