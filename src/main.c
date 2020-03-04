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

	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");//todo d
	mlx = ft_create_t_mlx();
//	ft_printf("FUCK START!\n");

	ft_check_args(argc, argv, mlx);
	ft_read_points_to_struct(argv, mlx);

	ft_printf("__points %d\n", mlx->map.total_points);
	//---------- check pars ----------
//	int i = 0;
//	while (i < mlx->map.total_points)
//	{
//		ft_printf("Point x = %d y = %d z = %d\n", mlx->map.px[i].x, mlx->map.px[i].y, mlx->map.px[i].z);
//		i++;
//	}
	//--------------------------------

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y,"fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->width, &mlx->endian);
	ft_printf("x=%d\n", mlx->map.len_x);//todo d
	ft_printf("y=%d\n", mlx->map.len_y);//TODO d
//	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	ft_draw_background(mlx);

//////		init start pos
//	//----------angle-----
//	mlx->angle_x = M_PI / 2;
//	mlx->angle_y = 0;
//	//--------------------

	ft_center_point(mlx);
	ft_write_double(mlx);

	mlx->map.angle = 0;
	ft_turn_coords(mlx);


	ft_draw_img_wireframe(*mlx);
	ft_draw_img_line(mlx->map.center, mlx->map.px[0], mlx);//todo del
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	ft_draw_img_menu(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_menu_ptr, 0, 0);
	ft_draw_img_menu_strings(mlx);
	ft_controls(mlx);
	mlx_loop(mlx->mlx_ptr);

	return (0);
}
