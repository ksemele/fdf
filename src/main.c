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
		mlx->slide = -10;
		ft_slide_x(mlx);
		ft_slide_y(mlx);
		ft_draw_wireframe(*mlx);
	}
	if (mlx->pressed == A)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -10;
		ft_slide_x(mlx);
		mlx->slide = 6;//todo lol kek -> not right
		ft_slide_x(mlx);
		ft_slide_y(mlx);
		ft_draw_wireframe(*mlx);
	}
	if (mlx->pressed == S)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 10;
		ft_slide_x(mlx);
		ft_slide_y(mlx);
		ft_draw_wireframe(*mlx);
	}
	if (mlx->pressed == N_D)//todo test img_mov
	{
//		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//		ft_draw_background(mlx);//TODO  WORKING! %)
//		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
//		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->window_x, mlx->window_y);
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
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx_s;

	mlx_s = ft_create_t_mlx();
	mlx_s->scale = 30;
	ft_check_args(argc, argv, mlx_s);
	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");//todo d
	mlx_s->mlx_ptr = mlx_init();
	mlx_s->win_ptr = mlx_new_window(mlx_s->mlx_ptr, mlx_s->win_x, mlx_s->win_y, "fdf");

	mlx_s->img_ptr = mlx_new_image(mlx_s->mlx_ptr, mlx_s->win_x, mlx_s->win_y);
	mlx_s->pixels = mlx_get_data_addr(mlx_s->img_ptr, &mlx_s->bpp, &mlx_s->size_line, &mlx_s->endian);
	ft_printf("x=%d\n", mlx_s->map.len_x);//todo d
	ft_printf("y=%d\n", mlx_s->map.len_y);//TODO d
	mlx_s->color = (int)CYBER;//TODO d
	mlx_put_image_to_window(mlx_s->mlx_ptr, mlx_s->win_ptr, mlx_s->img_ptr, 0, 0);
//	ft_draw_wireframe(*mlx_s);//TODO  WORKING! %)
//	ft_draw_line(mlx_s->map.point[0], mlx_s->map.point[10], mlx_s);//todo test line

	ft_draw_background(mlx_s);//TODO  WORKING! %)
//	ft_draw_img_line(mlx_s->map.point[0], mlx_s->map.point[10], mlx_s);//TODO  WORKING! %)
	ft_draw_img_wireframe(*mlx_s);//TODO createt it
	mlx_put_image_to_window(mlx_s->mlx_ptr, mlx_s->win_ptr, mlx_s->img_ptr, 0, 0);
	mlx_key_hook(mlx_s->win_ptr, ft_deal_key, mlx_s);
	mlx_loop(mlx_s->mlx_ptr);
	return (0);
}
