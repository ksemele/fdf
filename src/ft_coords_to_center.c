/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords_to_center.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:54:34 by cghael            #+#    #+#             */
/*   Updated: 2020/03/02 11:54:36 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//static void		ft_center_point(t_mlx *mlx)
//{
//	double	cathet_op;
//	double	cathet_ad;
//
//	mlx->map.center.x_d = (double)mlx->win_x / 2;
//	mlx->map.center.y_d = (double)mlx->win_y / 2;
////	mlx->map.center.z_d =
//	cathet_op = fabs((double)mlx->map.px[0].x_d + \
//			(double)(mlx->map.px[0].x_d - \
//			mlx->map.px[mlx->map.total_points - 1].x_d) / 2);
//	cathet_ad = fabs(mlx->map.px[0].y_d + \
//			(double)(mlx->map.px[0].y_d - \
//			mlx->map.px[mlx->map.total_points - 1].y_d) / 2);
//	mlx->map.angle = asin(cathet_op / sqrt(pow(cathet_op, 2) + \
//			pow(cathet_ad, 2)));
//}

//static void		ft_write_double(t_mlx *mlx)
//{
//	int i;
//
//	i = 0;
//	while (i < mlx->map.total_points)
//	{
//		mlx->map.px[i].z_d = (double) mlx->map.px[i].z;
//		mlx->map.px[i].y_d = (double) mlx->map.px[i].y;
//		mlx->map.px[i].x_d = (double) mlx->map.px[i].x;
//		i++;
//	}
//}

void	ft_coords_to_center(t_mlx *mlx)
{
	double	delta_x;
	double	delta_y;
	int	i;

	i = 0;
//	ft_write_double(mlx);
//	ft_center_point(mlx);
	delta_x = mlx->map.center.x_d + sin(mlx->map.angle) * mlx->map.a_o;
//	ft_printf("sin(mlx->map.angle) * mlx->map.a_o = %f\n", sin(mlx->map.angle) * mlx->map.a_o);
	delta_y = mlx->map.center.y_d + cos(mlx->map.angle) * mlx->map.a_o;
//	ft_printf("cos(mlx->map.angle) * mlx->map.a_o = %f\n", cos(mlx->map.angle) * mlx->map.a_o);
//	delta_x = mlx->map.center.x_d + ((double)(mlx->map.px[0].x_d - \
//				mlx->map.px[mlx->map.total_points - 1].x_d) / 2);
//	delta_y = mlx->map.center.y_d + ((double)(mlx->map.px[0].y_d - \
//				mlx->map.px[mlx->map.total_points - 1].y_d) / 2);
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].x_d += round(delta_x);
		mlx->map.px[i].y_d += round(delta_y);
		i++;
	}
}