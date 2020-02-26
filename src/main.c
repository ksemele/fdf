/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:01:39 by cghael            #+#    #+#             */
/*   Updated: 2020/02/25 17:22:09 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						ft_count_words(char *str);
void					ft_read_points_to_struct(int argc, char **argv, t_mlx *mlx);
void					ft_read_xyz(char *line, int cur_y, t_mlx *mlx);

void			ft_check_test(int argc, char **argv, t_mlx *mlx)
{
	char		**line;
	int			gnl;
	int			fd;

	fd = argc;
	line = (char**)malloc(1);
	*line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error_print("Error open file\n", mlx);
	//--------count lines
	gnl = ft_get_next_line(fd, line);
	while(gnl == 1)
	{
		mlx->map.len_y++;
		mlx->map.total_points += ft_count_words(*line);
		if(mlx->map.len_y == 1)
			mlx->map.len_x = mlx->map.total_points;
		gnl = ft_get_next_line(fd, line);
	}
	close(fd);
	//---------allocate memory for map
	ft_printf("total_points %d\n", mlx->map.total_points);
	mlx->map.px = (t_point*)malloc(sizeof(t_point) * mlx->map.total_points);//TODO leak protection, malloc err
	//---------fill map
	ft_printf("start fill\n");
	ft_read_points_to_struct(argc, argv, mlx);
}

void			ft_read_points_to_struct(int argc, char **argv, t_mlx *mlx)
{
	char		**line;
	int			gnl;
	int			fd;
	int			cur_y;

	fd = argc;
	cur_y = 0;
	ft_printf("total_ %d\n", mlx->map.total_points);
	mlx->map.total_points = 0;
	line = (char**)malloc(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error_print("Error open file\n", mlx);
	gnl = ft_get_next_line(fd, line);
	ft_printf("LEN Y %d\n", mlx->map.len_y);
	while(gnl == 1 && cur_y < mlx->map.len_y)
	{
		//TODO MVP reading, need integrate ft_atoi_base() and other
		ft_read_xyz(*line, cur_y, mlx);
		free(line);
		line = (char**)malloc(1);
		ft_printf("read %d line_1\tgnl = %d\n", cur_y, gnl);
		gnl = ft_get_next_line(fd, line);

		if (gnl <= 0)
			break;
		cur_y++;
	}
	close(fd);
}

void			ft_read_xyz(char *line, int cur_y, t_mlx *mlx)
{
	int			cur_point;
	int			cur_x;
	char		*tmp;

	cur_point = mlx->map.total_points;
	ft_printf("cur_ %d, total_ %d\n", cur_point, mlx->map.total_points);
	cur_x = 0;
	while(*line != '\0' && cur_x <= mlx->map.len_x)
	{
		tmp = line;
		while (*line == ' ')
		{
			if(*line == '\0')
				break ;
			line++;
		}
		mlx->map.px[cur_point].z = ft_atoi(tmp) * mlx->scale;
		mlx->map.px[cur_point].y = cur_y * mlx->scale;
		mlx->map.px[cur_point].x = cur_x * mlx->scale;
		mlx->map.px[cur_point].color = CYBER + 8000;
		mlx->map.px[cur_point].z_d = (double)mlx->map.px[cur_point].z;
		mlx->map.px[cur_point].y_d = (double)mlx->map.px[cur_point].y;
		mlx->map.px[cur_point].x_d = (double)mlx->map.px[cur_point].x;
		cur_x++;
		while(*line != ' ')
		{
			if(*line != '\0')
				break ;
			line++;
		}
		cur_point++;
		line++;
	}
	mlx->map.total_points = cur_point;
}

int				ft_count_words(char *str)
{
	char		*tmp;
	int			words;

	words = 0;
	tmp = str;

	while (*str != '\0')
		str++;
	while (tmp && tmp != str)
	{
		if (tmp == str)
			break ;
		while (*tmp == ' ')
		{
			if (tmp == str)
				break ;
			tmp++;
		}
		if (*tmp != ' ')
			words++;
		while (*tmp != ' ')
		{
			if (tmp == str)
				break ;
			tmp++;
		}
	}
	return (words);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx;

	ft_printf("\e[1;36moh, \e[1;31myes! \e[1;32mthis is fdf! \e[1;36m:3\e[m\n");//todo d
	mlx = ft_create_t_mlx();
//	ft_printf("FUCK START!\n");

	ft_check_test(argc, argv, mlx);
//	ft_check_args(argc, argv, mlx);
	ft_printf("__points %d\n", mlx->map.total_points);

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->width, &mlx->endian);
	ft_printf("x=%d\n", mlx->map.len_x);//todo d
	ft_printf("y=%d\n", mlx->map.len_y);//TODO d
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	ft_draw_background(mlx);

	//	init start pos
	mlx->slide = mlx->win_y / 2;
	ft_slide_x(mlx);
//	ft_slide_x(mlx);
	mlx->slide = -(mlx->win_y / 2);
	ft_slide_y(mlx);
//	int i = 0;
//	while(i < 4)
//	{		mlx->slide = -50;
//		ft_slide_x(mlx);
//		mlx->slide = 50;
//		ft_slide_y(mlx);
//	i++;
//	}
//	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//	mlx->slide = 50;
//	ft_slide_x(mlx);
//	ft_slide_y(mlx);


	ft_draw_img_wireframe(*mlx);
//	ft_draw_img_line(mlx->map.px[0], mlx->map.px[1], mlx);
//	ft_draw_img_line(mlx->map.px[0], mlx->map.px[2], mlx);
//	ft_draw_img_line(mlx->map.px[1], mlx->map.px[3], mlx);
//	ft_draw_img_line(mlx->map.px[2], mlx->map.px[3], mlx);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);

//print all points from map
//	int i = 0;
//	while(i < mlx->map.total_points)
//	{
//		ft_printf("%d ", mlx->map.px[i].z / mlx->scale);
//		i++;
//	}
//	ft_printf("\n");

	return (0);
}
