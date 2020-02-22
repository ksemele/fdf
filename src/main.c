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

static int				ft_deal_key(int key, t_mlx *mlx)
{
	ft_printf("key is: int [%1$d]\n", key);//нажали кнопку - зажгли пиксель
	mlx->pressed = key;
	if (mlx->pressed == W)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -50;
		ft_slide_x(mlx);
		ft_slide_y(mlx);
//		ft_draw_wireframe(*mlx);
		ft_draw_img_wireframe(*mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	if (mlx->pressed == A)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -50;
		ft_slide_x(mlx);
		mlx->slide = 50;//todo lol kek -> not right
		ft_slide_x(mlx);
		ft_slide_y(mlx);
//		ft_draw_wireframe(*mlx);
		ft_draw_img_wireframe(*mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	if (mlx->pressed == S)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 50;
		ft_slide_x(mlx);
		ft_slide_y(mlx);
//		ft_draw_wireframe(*mlx);
		ft_draw_img_wireframe(*mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	if (mlx->pressed == D)//todo test img_mov
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 50;
		ft_slide_x(mlx);
		mlx->slide = -50;
		ft_slide_y(mlx);
//		ft_draw_wireframe(*mlx);
		ft_draw_img_wireframe(*mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	if (key == SPACE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_draw_background(mlx);//TODO  WORKING! %)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	if (key == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
//		ft_free();//todo
		exit (0);
	}
	if (key == NUM_PLUS)//TODO not work (
	{
		mlx->scale += 20;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//		ft_draw_wireframe(*mlx);
		ft_draw_img_wireframe(*mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx;

	mlx = ft_create_t_mlx();
	mlx->scale = 20;
	ft_check_args(argc, argv, mlx);
	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");//todo d
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "fdf");

	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->width, &mlx->endian);
	ft_printf("x=%d\n", mlx->map.len_x);//todo d
	ft_printf("y=%d\n", mlx->map.len_y);//TODO d
	mlx->color = (int)CYBER;//TODO d
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 100, 0);
//	ft_draw_wireframe(*mlx);//TODO  WORKING! %)
//	ft_draw_line(mlx->map.point[0], mlx->map.point[10], mlx);//todo test line

	ft_draw_background(mlx);//TODO  WORKING! %)
//	ft_draw_img_line(mlx->map.point[0], mlx->map.point[10], mlx);//TODO  WORKING! %)
	ft_draw_img_wireframe(*mlx);//TODO createt it
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
