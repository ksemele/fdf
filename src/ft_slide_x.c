/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slide_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:45:17 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/21 13:45:18 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_slide_x(t_mlx *mlx_s)
{
	int					count;
	t_point				*ptr;

	ptr = mlx_s->map.point;
	count = mlx_s->map.len_x * mlx_s->map.len_y;
	while(count)
	{
		ptr->x += mlx_s->slide;
		if (count - 1)
			ptr++;
		count--;
	}
}
