/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:51:05 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/02 10:51:06 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_mouse_press(int key, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	if (key == MOUSE_SCROLL_UP)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if ((mlx->scale < 50) && (mlx->scale >= 1))
		{
			mlx->scale += 1;
//			mlx->scale_z = mlx->scale / 2;
		}
		ft_scale_points(mlx);
	}
	if (key == MOUSE_SCROLL_DOWN)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->scale >= 2)
		{
			mlx->scale -= 1;
//			mlx->scale_z = mlx->scale / 2;
		}
		ft_scale_points(mlx);
	}
	else if (key == MOUSE_LEFT_BUTTON && mlx->mouse.x > 0 && mlx->mouse.y > 0)
		mlx->mouse.is_pressed = 1;
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
	return (0);
}
