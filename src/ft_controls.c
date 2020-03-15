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
	mlx_hook(mlx->win_ptr, 2, 0, ft_deal_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_close, mlx);
}
