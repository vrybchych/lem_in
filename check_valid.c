/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:23:36 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/26 09:51:00 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_existing_room(char *s, char **rooms)
{
	int		i;

	i = 0;
	while (i < g_rooms_count)
	{
		if (!ft_strcmp(s, rooms[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_link(char *s, char **rooms)
{
	char	**tmp;
	int		res;

	res = 0;
	tmp = ft_strsplit(s, '-');
	if (tmp[0] && is_existing_room(tmp[0], rooms))
		res++;
	if (tmp[1] && is_existing_room(tmp[1], rooms))
		res++;
	if (!tmp[2] && res == 2)
		return (1);
	return (0);
}

void		check_valid(char **tab, char **rooms)
{
	int		i;

	i = 1;
	if (g_start == -1 || g_end == -1 || g_ants < 1)
		ft_error();
	while (tab[i])
	{
		if (tab[i][0] == '#')
			i++;
		else if (is_room(tab[i]))
			i++;
		else if (is_link(tab[i], rooms))
			i++;
		else
			ft_error();
	}
}
