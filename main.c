/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:14:17 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/26 09:57:49 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int			main(void)
{
	char	**tab;
	char	**rooms;
	int		**links;
	int		**routes;

	tab = reader();
	rooms = get_rooms(tab);
	set_globals(tab, rooms);
	check_valid(tab, rooms);
	links = set_links(tab, rooms);
	routes = set_routes(links);
	if (!routes[0][0])
		ft_error();
	ft_print_tab(tab);
	move(routes, rooms);
	ft_free_tab(rooms);
	ft_free_tab(tab);
	return (0);
}
