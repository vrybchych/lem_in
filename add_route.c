/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_route.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 09:44:19 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 15:52:01 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	**copy_routes(int **nr, int **r, int *route)
{
	int		i;

	i = 1;
	while (i < nr[0][0])
	{
		nr[i] = r[i];
		i++;
	}
	nr[i] = route;
	return (nr);
}

int			**add_route(int **routes, int *route)
{
	int		**new_routes;

	new_routes = create_routes_tab(routes[0][0] + 1);
	new_routes = copy_routes(new_routes, routes, route);
	free(routes);
	return (new_routes);
}
