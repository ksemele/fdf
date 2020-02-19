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

static int	ft_check_long_line(const char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (i == 0 || line[i - 1] == ' ')
				count++;
		}
		i++;
	}
	return (count);
}

void	ft_check_line_points(char *line, t_mlx *mlx_s)
{
	int count;

	count = 0;
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_error_print("No data found.\n", mlx_s);
	}
	else
		count = ft_check_long_line(line);
	if (count != mlx_s->map.len_x)
	{
		free(line);
		ft_error_print("Found wrong line length. Exiting.\n", mlx_s);
	}
}