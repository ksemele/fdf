/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_points_to_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:19:37 by cghael            #+#    #+#             */
/*   Updated: 2020/02/26 15:19:40 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_check_base(const char *str)
{
	if (str[0] == '0')
	{
		if (str[1] == 'x' || str[1] == 'X')
			return (16);
		else
			return (8);
	}
	return (10);
}

static void		ft_check_color(char *line, int cur_point, t_mlx *mlx)
{
	int base;

	while (*line)
	{
		if (*line == ' ')
		{
			mlx->map.px[cur_point].color = CYBER + 80;
			return ;
		}
		if (*line == ',')
		{
			line++;
			base = ft_check_base(line);
			if (base == 8)
				line++;
			else if (base == 16)
				line += 2;
			mlx->map.px[cur_point].color = ft_atoi_base(line, base);
			return ;
		}
		line++;
	}
	mlx->map.px[cur_point].color = CYBER + 80;
}

static void		ft_read_xyz(char *line, int cur_y, t_mlx *mlx)
{
	int			cur_point;
	int			cur_x;
	int			base;

	cur_point = mlx->map.total_points;
	cur_x = 0;
	while (*line && cur_x < mlx->map.len_x)
	{
		if (*line == ' ')
			line++;
		else
		{
			base = ft_check_base(line);
			mlx->map.px[cur_point].z = ft_atoi_base(line, base);
			mlx->map.px[cur_point].y = cur_y;
			mlx->map.px[cur_point].x = cur_x;
			ft_check_color(line, cur_point, mlx);
			while (*line != ' ' && *line != '\0')
				line++;
			cur_x++;
			cur_point++;
		}
	}
	mlx->map.total_points = cur_point;
}

static void ft_start_scale(t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->scale = 20;
	while (i < mlx->map.total_points)
	{
		mlx->map.px[i].z *= (int)mlx->scale;
		mlx->map.px[i].y *= (int)mlx->scale;
		mlx->map.px[i].x *= (int)mlx->scale;
		i++;
	}
}

void			ft_read_points_to_struct(char **argv, t_mlx *mlx)
{
	char		*line;
	int			gnl;
	int			fd;
	int			cur_y;

	cur_y = 0;
	if (!(mlx->map.px = (t_point*)malloc(sizeof(t_point) * \
			mlx->map.total_points)))
		ft_error_print("Error malloc ft_read_points_to_struct\n", mlx);
	mlx->map.total_points = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error_print("Error open file\n", mlx);
	gnl = ft_get_next_line(fd, &line);
	while (gnl > 0 && cur_y < mlx->map.len_y)
	{
		ft_read_xyz(line, cur_y, mlx);
		free(line);
		gnl = ft_get_next_line(fd, &line);
		cur_y++;
	}
	ft_start_scale(mlx);
	mlx->scale = 1;
	close(fd);
}
