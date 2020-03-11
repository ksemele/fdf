/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leathertube <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:29:32 by leathertu         #+#    #+#             */
/*   Updated: 2020/02/21 00:29:33 by leathertu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_draw_background(t_mlx *mlx_s)
{
	int		*pixel;
	int		i;

	ft_bzero(mlx_s->pixels, \
		(mlx_s->win_x * (mlx_s->win_y - mlx_s->win_menu_y) * \
		(mlx_s->bpp / 8)));
	pixel = (int *)(mlx_s->pixels);
	i = 0;
	while (i < mlx_s->win_x * (mlx_s->win_y - mlx_s->win_menu_y))
	{
		pixel[i] = BACKGROUND;
		i++;
	}
}
