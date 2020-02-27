/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:34:14 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/20 12:34:15 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** DESCRIPTION
** ft_isometric() convert px coordinates into isometric projection
** default angle = 0.8 for canonic projection
** Formulas received from a random github repo.
*/

void		ft_isometric(t_point *point, t_mlx *mlx_s)
{
	point->x = (point->x - point->y) * (int)cos((double)mlx_s->angle_x);
	point->y = (point->x + point->y) * (int)sin((double)mlx_s->angle_y) \
			- point->z;
	point->x_d = (point->x_d - point->y_d) * cos(mlx_s->angle_x);
	point->y_d = (point->x_d + point->y_d) * sin(mlx_s->angle_y) - point->z_d;
}
