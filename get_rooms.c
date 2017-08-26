/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:57:43 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 16:03:27 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	**fill_rooms_tab(char **tab, char **rooms)
{
	int		i;
	int		j;
	char	**tmp_tab;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (is_room(tab[i]))
		{
			tmp_tab = ft_strsplit(tab[i], ' ');
			rooms[j++] = ft_strdup(tmp_tab[0]);
			ft_free_tab(tmp_tab);
		}
		i++;
	}
	return (rooms);
}

static void	set_rooms_count(char **tab)
{
	int		i;

	i = 0;
	g_rooms_count = 0;
	while (tab[i])
	{
		if (is_room(tab[i]))
			g_rooms_count++;
		i++;
	}
}

static char	**create_rooms_tab(char **tab)
{
	int		i;
	char	**rooms;

	i = 0;
	set_rooms_count(tab);
	rooms = (char**)malloc(sizeof(char*) * (g_rooms_count + 1));
	while (i <= g_rooms_count)
		rooms[i++] = 0;
	return (rooms);
}

char		**get_rooms(char **tab)
{
	char	**rooms;

	rooms = create_rooms_tab(tab);
	rooms = fill_rooms_tab(tab, rooms);
	return (rooms);
}
