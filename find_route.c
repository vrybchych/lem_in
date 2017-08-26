/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:25:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 15:59:06 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** route[0] - length of route
** cr - current rooom
*/

static int	set_next_step1(int **status, int **links, int length, int cr)
{
	int		i;

	i = 0;
	while (i < g_rooms_count)
	{
		if (status[i][1] == length && links[i + 1][cr + 1])
			return (i);
		i++;
	}
	return (-1);
}

static int	*create_new_route(int length)
{
	int		*new_route;

	length = length + 2;
	new_route = (int*)malloc(sizeof(int) * length);
	return (new_route);
}

int			*find_route(int **status, int **links)
{
	int		length;
	int		*route;
	int		cr;

	length = status[g_end][1];
	route = create_new_route(length);
	route[0] = length;
	cr = g_end;
	while (length >= 0)
	{
		route[length + 1] = cr;
		cr = set_next_step1(status, links, length - 1, cr);
		length--;
	}
	return (route);
}
