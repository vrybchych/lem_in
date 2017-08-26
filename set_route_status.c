/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_route_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:15:18 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/25 20:58:31 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  int	**status
**  i - room index-1??
**  status[i][0] - room mark, 0 - white, 1 - grey, 2 -black
**  status[i][1] - distance from start
**
**  изначально помечаем старт серым и ставим dist = 0,
**                        изначально дист для всех -1
**  отмечаем комнаты занятые маршрутом черным
*/

static int	**set_dist(int **status, int dist, int **links, int room_index)
{
	int		i;

	i = 0;
	while (i < g_rooms_count)
	{
		if (links[i + 1][room_index + 1] && !status[i][0])
			status[i][1] = dist + 1;
		i++;
	}
	return (status);
}

static int	**mark_rooms(int dist, int **status)
{
	int		i;

	i = 0;
	while (i < g_rooms_count)
	{
		if (status[i][1] == dist)
			status[i][0] = 2;
		else if (status[i][1] == dist + 1)
			status[i][0] = 1;
		i++;
	}
	return (status);
}

static int	**mark_routes(int **status, int **routes)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < g_rooms_count)
	{
		j = 1;
		while (j <= routes[0][0])
		{
			k = 2;
			while (k <= routes[j][0])
			{
				status[routes[j][k]][0] = 2;
				k++;
			}
			j++;
		}
		i++;
	}
	return (status);
}

static int	**update_status(int **routes)
{
	int		i;
	int		**status;

	i = 0;
	status = (int**)malloc(sizeof(int*) * g_rooms_count);
	while (i < g_rooms_count)
	{
		status[i] = (int*)malloc(sizeof(int) * 2);
		status[i][0] = 0;
		status[i][1] = -1;
		i++;
	}
	mark_routes(status, routes);
	status[g_start][0] = 1;
	status[g_start][1] = 0;
	return (status);
}

int			**set_route_status(int **links, int **routes, int no_way)
{
	int		**status;
	int		dist;
	int		i;

	dist = 0;
	status = update_status(routes);
	while (status[g_end][1] == -1)
	{
		i = 0;
		no_way = 1;
		while (i < g_rooms_count)
		{
			if (status[i][0] == 1)
			{
				no_way = 0;
				status = set_dist(status, dist, links, i);
			}
			i++;
		}
		if (no_way)
			return (NULL);
		status = mark_rooms(dist, status);
		dist++;
	}
	return (status);
}
