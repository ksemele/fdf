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

int				main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;

	ft_check_args(argc, argv);
	ft_putstr(LEAK);
	perror("main()");
	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is ft_printf! \e[1;36m:3\e[m\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 100, 100, "lol");
	mlx_loop(mlx_ptr);
	return (0);
}