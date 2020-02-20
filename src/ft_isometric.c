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
** ft_isometric() convert point coordinates into isometric projection
** default angle = 0.8 for canonic projection
** Formulas received from a random github repo.
*/

void		ft_isometric(t_point *point, t_mlx *mlx_s)
{
	point->x_f = (point->x_f - point->y_f) * cosf(mlx_s->angle);
	point->y_f = (point->x_f + point->y_f) * sinf(mlx_s->angle) - point->z_f;
}
