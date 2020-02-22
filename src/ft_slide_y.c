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

void				ft_slide_y(t_mlx *mlx_s)
{
	int					count;
	t_point				*ptr;

	ptr = mlx_s->map.point;
	count = mlx_s->map.len_x * mlx_s->map.len_y;
	while(count > 0)
	{
		ptr->y_f += (float)mlx_s->slide;
		if (count - 1 > 0)
			ptr++;
		count--;
	}
}

