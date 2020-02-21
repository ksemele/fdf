/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_t_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:02:06 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/19 11:02:07 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*ft_create_t_mlx(void)
{
	t_mlx	*mlx_s;

	if (!(mlx_s = malloc(sizeof(t_mlx))))
		ft_error_print(MALLOC_ERROR, NULL);
	ft_bzero(mlx_s, sizeof(t_mlx));
	mlx_s->mlx_ptr = NULL;
	mlx_s->win_ptr = NULL;
	mlx_s->img_ptr = NULL;
//	mlx_s->pixels = NULL;
	mlx_s->map.point = NULL;
	mlx_s->win_x = 800;
	mlx_s->win_y = 600;
	mlx_s->angle = 0.8;
	return (mlx_s);
}
