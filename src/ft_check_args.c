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

static void		ft_usage_argc(int argc)
{
	if (argc != 2)
		ft_error_print(USAGE);
}

void	ft_check_args(int argc, char **argv)
{
	errno = 0;
	ft_usage_argc(argc);
	argv++;
}