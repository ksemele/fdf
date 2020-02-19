/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:03:42 by cghael            #+#    #+#             */
/*   Updated: 2020/02/13 14:03:45 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Checking the number of args and the file to valid map.
** If there are some problems, the program exit(1).
*/

static void		ft_usage_argc(int argc, t_mlx *mlx_s)
{
	if (argc != 2)
		ft_error_print(USAGE, mlx_s);
}

static void		ft_write_map_length_x(char *line, t_mlx *mlx_s)
{
	int i;

	i = 0;
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_error_print("No data found.\n", mlx_s);
	}
	else
	{
		while (line[i])
		{
			if (line[i] != ' ')
			{
				if (i == 0 || line[i - 1] == ' ')
					mlx_s->map.len_x++;
			}
			i++;
		}
	}
}

static void		ft_check_n_write_line(char *line, t_mlx *mlx_s)
{
	mlx_s->map.len_y++;
	if (mlx_s->map.len_x == 0)
		ft_write_map_length_x(line, mlx_s);
	else
		ft_check_line_points(line, mlx_s);
	if (!ft_increase_point_size(mlx_s))
	{
		free(line);
		ft_error_print("Malloc error in ft_check_n_write_line\n", mlx_s);
	}
	ft_write_points(line, mlx_s);
}

void	ft_check_args(int argc, char **argv, t_mlx *mlx_s)
{
	int		fd;
	char	*line;
	int		gnl;

	errno = 0;
	line = NULL;
	ft_usage_argc(argc, mlx_s);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error_print("Error open file\n", mlx_s);
	while ((gnl = ft_get_next_line(fd, &line)) == 1)
	{
		ft_check_n_write_line(line, mlx_s);
		free(line);
		line = NULL;
	}
	if (gnl == -1)
	{
		if (line != NULL)
			free(line);
		ft_error_print("Error open file\n", mlx_s);
	}
	close(fd);
}