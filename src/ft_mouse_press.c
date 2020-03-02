/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:51:05 by ksemele           #+#    #+#             */
/*   Updated: 2020/03/02 10:51:06 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_mouse_press(int key, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
	{
//		ft_zoom(key, mlx);//TODO ft_zoom()
	ft_printf("scrolling\n");
	}
	else if (key == MOUSE_LEFT_BUTTON && mlx->mouse.x > 0 && mlx->mouse.y > 0)
		mlx->mouse.is_pressed = 1;
	return (0);
}
