/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_routes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:36:30 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/25 20:57:49 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  routes[0][0] - count of route
*/

static int	*start_end_route(void)
{
	int		*route;

	route = (int*)malloc(sizeof(int) * 3);
	route[0] = 1;
	route[1] = g_start;
	route[2] = g_end;
	return (route);
}

int			**create_routes_tab(int size)
{
	int		**routes;

	routes = (int**)malloc(sizeof(int*) * (size + 1));
	routes[0] = (int*)malloc(sizeof(int));
	routes[0][0] = size;
	return (routes);
}

int			**set_routes(int **links)
{
	int		**routes;
	int		*route;
	int		**status;

	routes = create_routes_tab(0);
	if (links[g_start + 1][g_end + 1])
	{
		route = start_end_route();
		routes = add_route(routes, route);
		links[g_start + 1][g_end + 1] = 0;
		links[g_end + 1][g_start + 1] = 0;
	}
	while (1)
	{
		status = set_route_status(links, routes, 1);
		if (!status)
			break ;
		route = find_route(status, links);
		routes = add_route(routes, route);
	}
	return (routes);
}
