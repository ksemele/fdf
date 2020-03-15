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

static void		ft_usage_argc(int argc, t_mlx *mlx)
{
	if (argc != 2)
		ft_error_print(USAGE, mlx);
}

static int		ft_count_words(char *str, t_mlx *mlx)
{
	int			count;
	int			i;
	int			j;

	count = 0;
	i = 0;
	j = 1;
	if (ft_strlen(str) > 0)
	{
		while (str[i])
		{
			if ((str[j] == ' ' || str[j] == '\0') && str[i] != ' ')
				count++;
			i++;
			j++;
		}
	}
	if (ft_strlen(str) == 0 || count == 0)
	{
		free(str);
		ft_error_print("No data found.\n", mlx);
	}
	return (count);
}

static void		ft_check_lines(char *line, t_mlx *mlx)
{
	int			words;

	words = ft_count_words(line, mlx);
	if (mlx->map.len_x == 0)
		mlx->map.len_x = words;
	else if (words < mlx->map.len_x)
	{
		free(line);
		ft_error_print("Found wrong line length. Exiting.\n", mlx);
	}
	mlx->map.total_points += mlx->map.len_x;
}

void			ft_check_args(int argc, char **argv, t_mlx *mlx)
{
	int			fd;
	char		*line;
	int			gnl;

	errno = 0;
	line = NULL;
	ft_usage_argc(argc, mlx);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error_print("Error open file\n", mlx);
	gnl = ft_get_next_line(fd, &line);
	while (gnl > 0)
	{
		mlx->map.len_y++;
		ft_check_lines(line, mlx);
		free(line);
		gnl = ft_get_next_line(fd, &line);
	}
	if (gnl == -1)
	{
		if (line != NULL)
			free(line);
		ft_error_print("Error open file\n", mlx);
	}
	close(fd);
}
