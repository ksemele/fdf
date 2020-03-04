/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img_menu_strings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:23:03 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/04 16:23:04 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_img_menu_strings(t_mlx *mlx)
{

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->win_menu_x / 2 - 40,
			3, CYBER & BACKGROUND,
			"Controls:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 23, BACKGROUND,
				   "Move: WASD / arrows / mouse LMB");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 43, BACKGROUND,
				   "Isometric: NUMPAD 1 / 2 / 3");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 370, 23, BACKGROUND,
				   "Rotate: NUMPAD 7 / 9");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 370, 43, BACKGROUND,
				   "Exit: Esc / red cross");

}
