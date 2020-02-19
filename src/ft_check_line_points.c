/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_points.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:32:42 by cghael            #+#    #+#             */
/*   Updated: 2020/02/19 16:32:44 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_small_line(char *line, t_mlx *mlx_s)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_error_print("Found wrong line length. Exiting.\n", mlx_s);
	}
	else
	{
		if (line[0] != ' ' && line[0] != '\t' && line[0] != '\n'
			&& line[0] != '\v' && line[0] != '\f' && line[0] != '\r')
		{
			free(line);
			ft_error_print("Found wrong line length. Exiting.\n", mlx_s);
		}
		else
			return (1);
	}
}

static int	ft_check_long_line(const char *line, t_mlx *mlx_s)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i - 1] != ' ')
			count++;
		i++;
	}
	return (count);
}

void	ft_check_line_points(char *line, t_mlx *mlx_s)
{
	int count;

	if (ft_strlen(line) < 2)
		count = ft_check_small_line(line, mlx_s);
	else
		count = ft_check_long_line(line, mlx_s);
	if (count != mlx_s->map.length_x)
	{
		free(line);
		ft_error_print("Found wrong line length. Exiting.\n", mlx_s);
	}
}