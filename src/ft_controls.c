/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:30:09 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/29 11:30:10 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Close window by press 'x' in left side
*/

static int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

/*
** Connect functions-controllers to window
*/

void			ft_controls(t_mlx *mlx)
{
//	mlx_hook(fdf->win, 2, 0, key_press, fdf);//todo this is template from brazhnik
//	mlx_hook(fdf->win, 17, 0, close, fdf);
//	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
//	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
//	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);

	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);//TODO ft_controls
	mlx_hook(mlx->win_ptr, 17, 0, ft_close, mlx);
}


