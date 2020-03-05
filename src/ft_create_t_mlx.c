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
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		ft_error_print(MALLOC_ERROR, NULL);
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->pixels = NULL;
	mlx->color = CYBER;
	mlx->angle_x = M_PI / 6;
	mlx->angle_y = M_PI / 3;
	mlx->scale = 1;
	mlx->scale_z = 1;
	mlx->win_x = 800;
	mlx->win_y = 600;
	mlx->light = 0;
	return (mlx);
}
