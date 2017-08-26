/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_next_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 09:20:53 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/25 10:00:59 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  int **ant - pointer to *ant
*/

static int	*find_free_route(int *ant, int *riu, int **routes, int i)
{
	if (*riu == -1 || routes[1][0] == 1)
	{
		ant[0] = routes[1][2];
		ant[1] = 1;
		*riu = 1;
		if (i == g_ants && routes[1][0] == 1)
			*riu = -2;
	}
	else if (*riu == routes[0][0] ||
			(*riu > 0 && routes[*riu][0] > (g_ants - i - 1)))
		*riu = -2;
	else
	{
		(*riu)++;
		ant[0] = routes[*riu][2];
		ant[1] = *riu;
	}
	return (ant);
}

static int	find_next_move(int room, int *route)
{
	int		i;

	i = 1;
	while (i < route[0] + 1)
	{
		if (route[i] == room)
			return (route[i + 1]);
		i++;
	}
	return (-1);
}

static int	*set_next_move(int *ant, int **routes)
{
	int		next_move;

	next_move = find_next_move(ant[0], routes[ant[1]]);
	ant[0] = next_move;
	return (ant);
}

int			*set_next_step(int *ant, int *riu, int **routes, int i)
{
	if (ant[0] == -1)
		ant = find_free_route(ant, riu, routes, i);
	else
		ant = set_next_move(ant, routes);
	return (ant);
}
