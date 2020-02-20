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

void	ft_draw_background(t_mlx *mlx_s)
{
	int	*image;
	int	i;

	ft_bzero(mlx_s->data_addr, mlx_s->window_x * mlx_s->window_y * (mlx_s->bits_per_pixel / 8));
	image = (int *)(mlx_s->data_addr);
	i = 0;
	while (i < mlx_s->window_x * mlx_s->window_y)
	{
		image[i] = BACKGROUND;
		i++;
	}
}
