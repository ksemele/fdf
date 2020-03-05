/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:03 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/05 13:14:03 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_img_all(t_mlx *mlx)
{
	if (mlx->map.iso == 1)
		ft_img_isometric(mlx);
	else if (mlx->map.iso == 2)
		ft_img_isometric2(mlx);
	else if (mlx->map.iso == 3)
		ft_img_isometric3(mlx);
	ft_draw_img_wireframe(*mlx);
	ft_draw_img_line(mlx->map.center, mlx->map.px[0], mlx); //todo del
	if (mlx->pressed == SPACE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
		ft_draw_background(mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_menu_ptr, 0, 0);
	ft_draw_img_menu_strings(mlx);
}
