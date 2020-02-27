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

	if ((int)point->x_d <= mlx->win_x && (int)point->y_d >= 0 && \
			(int)point->y_d <= mlx->win_y)//TODO px->y_d >(>=) 0 ?
	{
		i = ((int)point->x_d * mlx->bpp / 8) + ((int)point->y_d * mlx->width);
		mlx->pixels[i] = (char)point->color;
		mlx->pixels[i + 1] = point->color >> 8;
		mlx->pixels[i + 2] = point->color >> 16;
	}
}

void			ft_draw_img_line(t_point start, t_point end, t_mlx *mlx)
{
	double		x_step;
	double		y_step;
	double		max;

//	ft_isometric(&start, mlx);
//	ft_isometric(&end, mlx);
	ft_printf("starx\tx y\t%d %d\t\t%.f %.f\t", start.x, start.y, start.x_d,start.y_d);
	ft_printf("end\tx y\t%d %d\t\t%.f %.f\n", end.x, end.y, end.x_d, end.y_d);
	x_step = end.x_d - start.x_d;
	y_step = end.y_d - start.y_d;
	ft_printf("step x y 1 %.f %.f\n", x_step, y_step);
	max = fmax(fabs(x_step), fabs(y_step));//TODO to double all
	ft_printf("max = %.f\n", max);
	x_step /= max;
	y_step /= max;
	ft_printf("step x y 2 %.f %.f\n", x_step, y_step);
	while((int)(end.x_d - start.x_d) || (int)(end.y_d - start.y_d))
	{
//		start.color = CYBER ;
//		end.color = CYBER ;
//		start.color += (int)(end.color / max);//todo how change colors?
//		if((int)start.x_d >= mlx->map.len_x && (int)start.y_d >= mlx->map.len_y)//todo think about it
//		{
			ft_draw_img_pixel(mlx, &start);
			ft_draw_img_pixel(mlx, &end);
//			ft_printf("strt x y->\t %.f\t%.f\n", start.x_d, start.y_d);
//			ft_printf("(int)(end.x_d - start.x_d)_y\t%d\t%d\n",
//					  (int)(end.x_d - start.x_d), (int)(end.y_d - start.y_d));
//		}
//		if ((int)(end.x_d - start.x_d) ==0 || (int)(end.y_d - start.y_d) == 0)
//			break ;
		start.x_d += x_step;
		start.y_d += y_step;
//		ft_printf("strt x y_@->\t %.f\t%.f\n", start.x_d, start.y_d);

	}
}