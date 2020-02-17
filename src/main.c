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
#include "mlx.h"

int				ft_deal_key(int key, t_mlx *param)
{
	if (key != 900)
		ft_printf("\n", param);
	ft_printf("key is: int [%1$d]", key);
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, 50, 50, 255);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx_s;

	ft_check_args(argc, argv);
	ft_putstr(LEAK);
	perror("main()");
	mlx_s = malloc(sizeof(t_mlx));//todo add ft_create_t_mlx() ft_bzero, etc
	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is ft_printf! \e[1;36m:3\e[m\n");
	mlx_s->mlx_ptr = mlx_init();
	mlx_s->win_ptr = mlx_new_window(mlx_s->mlx_ptr, 100, 100, "fdf");
	mlx_key_hook(mlx_s->win_ptr, ft_deal_key, mlx_s);
	mlx_loop(mlx_s->mlx_ptr);
	return (0);
}