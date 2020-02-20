/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:01:39 by cghael            #+#    #+#             */
/*   Updated: 2020/02/13 13:01:42 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



static int				ft_deal_key(int key, t_mlx *mlx_s)
{
	if (mlx_s->pressed < 10)
		mlx_string_put(mlx_s->mlx_ptr, mlx_s->win_ptr, 100, 100, mlx_s->color, "EBAT 1");
	mlx_s->pressed = key;
	ft_printf("key is: int [%1$d]\n", key);//нажали кнопку - зажгли пиксель

//	mlx_s->color <<= 16;
	if (mlx_s->pressed > 10)
	{
//		mlx_clear_window(mlx_s->mlx_ptr, mlx_s->win_ptr);
		mlx_string_put(mlx_s->mlx_ptr, mlx_s->win_ptr, 110, 110, mlx_s->color, "EBAT 2");
		mlx_s->pressed = 1;
	}
	if (key == SPACE)
		mlx_clear_window(mlx_s->mlx_ptr, mlx_s->win_ptr);
	if (key == ESC)
	{
		mlx_destroy_window(mlx_s->mlx_ptr, mlx_s->win_ptr);
//		ft_free();//todo
		exit (0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx_s;

//	errno = 0;
	mlx_s = ft_create_t_mlx();
	mlx_s->scale = 30;
	ft_check_args(argc, argv, mlx_s);
	perror("main()");
	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");//todo d
	mlx_s->mlx_ptr = mlx_init();
	mlx_s->win_ptr = mlx_new_window(mlx_s->mlx_ptr, mlx_s->window_x, mlx_s->window_y, "fdf");

	mlx_s->img_ptr = mlx_new_image(mlx_s->mlx_ptr, mlx_s->window_x, mlx_s->window_y);
	mlx_s->data_addr = mlx_get_data_addr(mlx_s->img_ptr, &mlx_s->bits_per_pixel, &mlx_s->size_line, &mlx_s->endian);
	ft_printf("x=%d\n", mlx_s->map.len_x);//todo d
	ft_printf("y=%d\n", mlx_s->map.len_y);//TODO d
	mlx_s->color = (int)CYBER;//TODO d
	mlx_put_image_to_window(mlx_s->mlx_ptr, mlx_s->win_ptr, mlx_s->img_ptr, 0, 0);
//	ft_draw_wireframe(*mlx_s);//for draw wireframe with pixel_puts, working correctly! :)
//	ft_draw_line(mlx_s->map.point[0], mlx_s->map.point[10], mlx_s);//todo test line
//	ft_draw_img_line(mlx_s->map.point[0], mlx_s->map.point[10], mlx_s);
	ft_draw_img_wireframe(*mlx_s);//TODO createt it
	mlx_key_hook(mlx_s->win_ptr, ft_deal_key, mlx_s);
	mlx_loop(mlx_s->mlx_ptr);
	return (0);
}
