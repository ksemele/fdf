/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:48 by cghael            #+#    #+#             */
/*   Updated: 2020/02/18 16:21:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error_print(char *str, t_mlx *mlx_s)
{
	if (mlx_s != NULL)
	{
		if (mlx_s->map.px != NULL)
			free(mlx_s->map.px);
		free(mlx_s);
	}
	if (errno)
		perror(str);
	else
		ft_putstr(str);
	exit(CODE_ERROR);
}
