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
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x + 100, mlx->win_y
	+ 100,"fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->width, &mlx->endian);
	ft_printf("x=%d\n", mlx->map.len_x);//todo d
	ft_printf("y=%d\n", mlx->map.len_y);//TODO d
//	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	ft_draw_background(mlx);

////		init start pos
//	mlx->slide = mlx->win_y / 2;
//	ft_slide_x(mlx);
//	ft_slide_x(mlx);
//	mlx->slide = -(mlx->win_y / 2);
//	ft_slide_y(mlx);
	int i = 0;//TODO to extern foo()
	while(i < mlx->map.total_points)
	{
		mlx->map.px[i].x_d = (mlx->map.px[i].x_d - mlx->map.px[i].y_d) * cos(mlx->angle_x);
		mlx->map.px[i].y_d = (mlx->map.px[i].x_d + mlx->map.px[i].y_d) * sin(mlx->angle_x) - mlx->map.px[i].z_d;
		i++;
	}

	ft_draw_img_wireframe(*mlx);
//	ft_draw_img_line(mlx->map.px[0], mlx->map.px[1], mlx);
//	ft_draw_img_line(mlx->map.px[0], mlx->map.px[2], mlx);
//	ft_draw_img_line(mlx->map.px[1], mlx->map.px[3], mlx);
//	ft_draw_img_line(mlx->map.px[2], mlx->map.px[3], mlx);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 50, 50);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);

//print all points from map
//	int i = 0;
//	while(i < mlx->map.total_points)
//	{
//		ft_printf("%d ", mlx->map.px[i].z / mlx->scale);
//		i++;
//	}
//	ft_printf("\n");

	return (0);
}
