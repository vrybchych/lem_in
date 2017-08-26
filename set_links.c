/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 08:23:32 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 16:17:51 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** r1r2 - current room
** ants[0] - count
*/

static int	is_link(char *s)
{
	if (s[0] == '#' || is_room(s))
		return (0);
	else
		return (1);
}

static int	**create_links_matrix(int count)
{
	int		**matrix;
	int		i;
	int		j;

	i = 0;
	matrix = (int**)malloc(sizeof(int*) * (count + 1));
	while (i <= count)
	{
		j = 0;
		matrix[i] = (int*)malloc(sizeof(int) * (count + 1));
		while (j <= count)
		{
			if (j == 0)
				matrix[i][j] = i;
			else if (i == 0)
				matrix[i][j] = j;
			else
				matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

static int	get_room_index(char *r, char **rooms)
{
	int		i;

	i = 0;
	while (rooms[i])
	{
		if (!ft_strcmp(r, rooms[i]))
			return (i + 1);
		i++;
	}
	ft_error();
	return (-1);
}

static int	**add_link(char **rooms, char **r1r2, int **links)
{
	int		n1;
	int		n2;

	n1 = get_room_index(r1r2[0], rooms);
	n2 = get_room_index(r1r2[1], rooms);
	links[n1][n2] = 1;
	links[n2][n1] = 1;
	return (links);
}

int			**set_links(char **tab, char **rooms)
{
	int		**links;
	int		i;
	char	**r1r2;

	i = 1;
	links = create_links_matrix(g_rooms_count);
	while (tab[i])
	{
		if (is_link(tab[i]))
		{
			r1r2 = ft_strsplit(tab[i], '-');
			links = add_link(rooms, r1r2, links);
			ft_free_tab(r1r2);
		}
		i++;
	}
	return (links);
}
