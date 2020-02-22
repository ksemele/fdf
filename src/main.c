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
	if (mlx->pressed == W || mlx->pressed == UP)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -50;
		ft_slide_x(mlx);
		ft_slide_y(mlx);
	}
	if (mlx->pressed == A || mlx->pressed == LEFT)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = -50;
		ft_slide_x(mlx);
		mlx->slide = 50;
		ft_slide_y(mlx);
	}
	if (mlx->pressed == S|| mlx->pressed == DOWN)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 50;
		ft_slide_x(mlx);
		ft_slide_y(mlx);
	}
	if (mlx->pressed == D || mlx->pressed == RIGHT)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->slide = 50;
		ft_slide_x(mlx);
		mlx->slide = -50;
		ft_slide_y(mlx);
	}

	if (mlx->pressed == NUM_PLUS)//TODO not work (
	{
		mlx->scale += 20;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_draw_wireframe(*mlx);
	}
	ft_draw_img_wireframe(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	if (mlx->pressed == SPACE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
		ft_draw_background(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	if (mlx->pressed == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
//		ft_free();//todo
		exit (0);
	}
	return (0);
}

//static void 	ft_print_map(t_mlx *mlx)
//{
//	int i = 0;
//	int k = 0;
//	while (k <= mlx->map.len_x)
//	{
//		i=0;
//		while (i <= 50)
//		{
//			ft_printf("%d ", mlx->map.point[i].z);
//			i++;
//		}
//		ft_printf("\n");
//		k++;
//	}
//}

int				main(int argc, char **argv)
{
	t_mlx		*mlx;

	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");//todo d
	mlx = ft_create_t_mlx();
	ft_printf("FUCK START!\n");
	ft_check_args(argc, argv, mlx);
//	ft_print_map(mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->width, &mlx->endian);
//	ft_printf("x=%d\n", mlx->map.len_x);//todo d
//	ft_printf("y=%d\n", mlx->map.len_y);//TODO d
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 100, 0);
	ft_draw_background(mlx);

	//	init start pos
	mlx->slide = mlx->win_y / 2;
	ft_slide_x(mlx);
	mlx->slide = -(mlx->win_y / 2);
	ft_slide_y(mlx);
	ft_draw_img_wireframe(*mlx);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
