/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:37:22 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/19 11:37:23 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *
*/

void		ft_draw_line(t_point start, t_point end, t_mlx *mlx_s)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = end.x_f - start.x_f;
	y_step = end.y_f - start.y_f;
	max = ft_fisbigger(ft_fmod(x_step), ft_fmod(y_step));

	x_step /= max;
	y_step /= max;
	while((int)(end.x_f - start.x_f) || (int)(end.y_f - start.y_f))
	{
		mlx_pixel_put(mlx_s->mlx_ptr, mlx_s->win_ptr, (int)start.x_f, \
				(int)start.y_f, start.color);
		start.x_f += x_step;
		start.y_f += y_step;
	}
}
