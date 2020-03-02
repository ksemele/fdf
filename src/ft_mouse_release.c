/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:51:37 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/02 10:51:38 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_mouse_release(int key, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	(void)key;
	mlx = (t_mlx *)param;
	mlx->mouse.is_pressed = 0;
	return (0);
}
