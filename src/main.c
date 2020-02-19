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

#define CYBER 0x9B1F6A
#define ESC 53
#define SPACE 49
#define W 13
#define A 0
#define S 1
#define D 2

static int				ft_deal_key(int key, t_mlx *mlx_s)
{
	if (mlx_s->pressed == 1)
		mlx_clear_window(mlx_s->mlx_ptr, mlx_s->win_ptr);
	mlx_string_put(mlx_s->mlx_ptr, mlx_s->win_ptr, 100, 100, mlx_s->color, "EBAT 1");
	mlx_s->pressed = key;
	ft_printf("key is: int [%1$d]\n", key);//нажали кнопку - зажгли пиксель
//	t_point *start = malloc(sizeof(t_point));
//	t_point *end = malloc(sizeof(t_point));
//	start->x = key;
//	start->y += key + 60;
//	start->x_f = (float)start->x;//todo into foo()
//	start->y_f = (float)start->y;
//	end->x = 160;
//	end->y = 290;
//	end->x_f = (float)end->x;
//	end->y_f = (float)end->y;
//	start->color = CYBER;
//	ft_draw_line(start, end, mlx_s);

	mlx_s->color <<= 16;
	if (mlx_s->pressed > 10)
	{
		mlx_clear_window(mlx_s->mlx_ptr, mlx_s->win_ptr);
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

	mlx_s = ft_create_t_mlx();
	mlx_s->scale = 30;
	ft_check_args(argc, argv, mlx_s);
	perror("main()");
	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");
	mlx_s->mlx_ptr = mlx_init();
	mlx_s->win_ptr = mlx_new_window(mlx_s->mlx_ptr, 800, 600, "fdf");
//	mlx_s->img_ptr = mlx_new_image(mlx_s->mlx_ptr, 360, 150);
//	mlx_s->data_addr = malloc(100000);

//	mlx_s->data_addr = mlx_get_data_addr(mlx_s->img_ptr, &a, &b, 0);
	ft_printf("x=%d\n", mlx_s->map.len_x);
	ft_printf("y=%d\n", mlx_s->map.len_y);
	mlx_s->color = (int)CYBER;
	ft_draw_wireframe(*mlx_s);
//	mlx_put_image_to_window(mlx_s->mlx_ptr, mlx_s->win_ptr, mlx_s->img_ptr, 50, 50);

	mlx_key_hook(mlx_s->win_ptr, ft_deal_key, mlx_s);
	mlx_loop(mlx_s->mlx_ptr);
	return (0);
}
