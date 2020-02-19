/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:13:28 by cghael            #+#    #+#             */
/*   Updated: 2020/02/19 18:13:29 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_check_base(const char *str)
{
	if (str[0] == '0')
	{
		if (str[1] == 'x' || str[1] == 'X')
			return (16);
		else
			return (8);
	}
	return (10);
}

static int		ft_move_i(const char *line, int i, t_point *point)
{
	int base;
	int color_flag;

	color_flag = 0;
	point->color = 0xffffff;
	while (line[i] && line[i] != ' ')
	{
		if (line[i] == ',' && color_flag == 0)
		{
			i++;
			base = ft_check_base(line + i);
			if (base == 8)
				i++;
			else if (base == 16)
				i += 2;
			point->color = ft_atoi_base(line + i, base);
			color_flag = 1;
		}
		i++;
	}
	return (i);
}

void			ft_write_points(const char *line, t_mlx *mlx_s)
{
	int i;
	int j;
	int x;
	int base;

	i = 0;
	x = 0;
	j = mlx_s->map.len_y * mlx_s->map.len_x - mlx_s->map.len_x;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
		{
			base = ft_check_base(line + i);
			mlx_s->map.point[j].z = ft_atoi_base(line + i, base);
			mlx_s->map.point[j].y = mlx_s->map.len_y - 1;
			mlx_s->map.point[j].x = x;
			i = ft_move_i(line, i, &mlx_s->map.point[j]);
			j++;
			x++;
		}
	}
}