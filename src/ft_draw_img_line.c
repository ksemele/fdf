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

static void		ft_draw_img_pixel(t_mlx *mlx_s, t_point point)
{
	int		i;

	if (point.x < mlx_s->window_x && point.y >= 0 && point.y < mlx_s->window_y)
	{
		i = (point.x * mlx_s->bits_per_pixel / 8) + (point.y * mlx_s->size_line);
		mlx_s->data_addr[i] = point.color;
		ft_printf("color=%d\n", point.color);
		mlx_s->data_addr[++i] = point.color >> 8;
		mlx_s->data_addr[++i] = point.color >> 16;
	}
}

static void	ft_draw_background(t_mlx *mlx_s)
{
	int	*image;
	int	i;

	ft_bzero(mlx_s->data_addr, mlx_s->window_x * mlx_s->window_y * (mlx_s->bits_per_pixel / 8));
	image = (int *)(mlx_s->data_addr);
	i = 0;
	while (i < mlx_s->window_x * mlx_s->window_y)
	{
		image[i] = BACKGROUND;
		i++;
//		image[i] = CYBER;
//		i++;
//		image[i] = BLACK;
//		i++;
//		image[i] = WHITE;
//		i++;
	}
}

void		ft_draw_img_line(t_point start, t_point end, t_mlx *mlx_s)
{
	ft_printf("%p\t%p\t%p\n", start, end, mlx_s);//todo d

	float	x_step;
	float	y_step;
	float	max;

	ft_draw_background(mlx_s);//TODO  WORKING! %)
	ft_isometric(&start, mlx_s);
	ft_isometric(&end, mlx_s);
	x_step = end.x_f - start.x_f;
	y_step = end.y_f - start.y_f;
	max = ft_fisbigger(ft_fmod(x_step), ft_fmod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(end.x_f - start.x_f) || (int)(end.y_f - start.y_f))
	{
		start.color += end.color / (int)ft_isbigger(ft_fmod(x_step), ft_fmod(y_step));//todo how change colors?
//		mlx_pixel_put(mlx_s->mlx_ptr, mlx_s->win_ptr, (int)start.x_f, \
//				(int)start.y_f, start.color);
		ft_draw_img_pixel(mlx_s, start);
		start.x_f += x_step;
		start.y_f += y_step;
		mlx_put_image_to_window(mlx_s->mlx_ptr, mlx_s->win_ptr, mlx_s->img_ptr, 0, 0);
	}
}