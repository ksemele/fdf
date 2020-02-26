/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increase_point_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:51:51 by cghael            #+#    #+#             */
/*   Updated: 2020/02/19 16:51:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*ft_copy_points_arr(t_point *tmp, t_mlx *mlx_s)
{
	int size;
	int i;

	i = 0;
	size = mlx_s->map.len_x * mlx_s->map.len_y;
	while (i < size)
	{
		tmp[i] = mlx_s->map.px[i];
		i++;
	}
	free(mlx_s->map.px);
	return (tmp);
}

int		ft_increase_point_size(t_mlx *mlx_s)
{
	t_point *tmp;

	if (mlx_s->map.px == NULL)
	{
		if (!(mlx_s->map.px = malloc(sizeof(t_point) * mlx_s->map.len_x)))
			return (0);
		return (1);
	}
	else
	{
		if (!(tmp = malloc(sizeof(t_point) * \
				(mlx_s->map.len_x * mlx_s->map.len_y))))
			return (0);
		tmp = ft_copy_points_arr(tmp, mlx_s);
		mlx_s->map.px = tmp;
	}
	return (1);
}