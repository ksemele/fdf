/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mem_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:10:48 by cghael            #+#    #+#             */
/*   Updated: 2020/02/19 14:10:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_memory		*ft_create_mem_struct(void)
{
	t_memory	*tmp;

	if (!(tmp = malloc(sizeof(t_memory))))
		ft_error_print("ft_create_mem_struct", NULL);
	ft_bzero(tmp, sizeof(t_memory));
	return (tmp);
}
