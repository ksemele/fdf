/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:46:20 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/04 15:46:21 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_draw_menu_bg(t_mlx *mlx)
{
	int				*pixel;
	int				i;

	ft_bzero(mlx->pixels_menu, mlx->win_menu_x * mlx->win_menu_y \
			* (mlx->bpp / 8));
	pixel = (int *)(mlx->pixels_menu);
	i = 0;
	while (i <= mlx->win_menu_x * mlx->win_menu_y)
	{
		pixel[i] = BACKGROUND << 1;
		i++;
	}
}

void				ft_draw_img_menu(t_mlx *mlx)
{
	mlx->win_menu_x = mlx->win_x;
	mlx->win_menu_y = mlx->win_y / 9;
	mlx->img_menu_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_menu_x, \
			mlx->win_menu_y );
	mlx->pixels_menu = mlx_get_data_addr(mlx->img_menu_ptr, &mlx->bpp, \
			&mlx->width_menu, &mlx->endian);

	ft_draw_menu_bg(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_menu_ptr, \
			0, 0);
}
