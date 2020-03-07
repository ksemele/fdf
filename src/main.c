/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:01:39 by cghael            #+#    #+#             */
/*   Updated: 2020/02/25 17:22:09 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_mlx		*mlx;

	mlx = ft_create_t_mlx();
	ft_check_args(argc, argv, mlx);
	ft_read_points_to_struct(argv, mlx);
	ft_printf("map x=%d\tmap y=%d\n", mlx->map.len_x, mlx->map.len_y);
	ft_printf("total points %d\n", mlx->map.total_points);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, \
			&mlx->width, &mlx->endian);
	ft_draw_background(mlx);
	ft_center_point(mlx);
	ft_write_double(mlx);
	ft_turn_coords(mlx);
	ft_draw_img_wireframe(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	ft_draw_img_menu(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
			mlx->img_menu_ptr, 0, 0);
	ft_draw_img_menu_strings(mlx);
	ft_controls(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
