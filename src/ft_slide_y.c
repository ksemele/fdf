/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slide_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:52:47 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/21 13:52:48 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_slide_y(t_mlx *mlx)
{
//	int				count;
//	t_point			*ptr;
//
//	ptr = mlx_s->map.px;
//	count = mlx_s->map.len_x * mlx_s->map.len_y;
//	while (count > 0)
//	{
//		ptr->y_w += (double)mlx_s->slide;
//		if (count - 1 > 0)
//			ptr++;
//		count--;
//	}
	mlx->map.center.y_d +=  (double)mlx->slide;
}
