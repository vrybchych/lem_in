/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_globals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:25:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 16:15:21 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_start(char *s, char **rooms)
{
	int		i;
	char	**tmp_tab;

	i = 0;
	tmp_tab = ft_strsplit(s, ' ');
	s = tmp_tab[0];
	while (i < g_rooms_count)
	{
		if (!(ft_strcmp(s, rooms[i])))
		{
			g_start = i;
			ft_free_tab(tmp_tab);
			return ;
		}
		i++;
	}
	ft_free_tab(tmp_tab);
}

static void	set_end(char *s, char **rooms)
{
	int		i;
	char	**tmp_tab;

	i = 0;
	tmp_tab = ft_strsplit(s, ' ');
	s = tmp_tab[0];
	while (i < g_rooms_count)
	{
		if (!(ft_strcmp(s, rooms[i])))
		{
			g_end = i;
			ft_free_tab(tmp_tab);
			return ;
		}
		i++;
	}
	ft_free_tab(tmp_tab);
}

static int	is_num(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_error();
			return (0);
		}
		i++;
	}
	return (1);
}

void		set_globals(char **t, char **rooms)
{
	int		i;

	i = 0;
	g_start = -1;
	g_end = -1;
	g_ants = 0;
	while (t[i])
	{
		if (i == 0 && is_num(t[i]))
			g_ants = ft_atoi(t[i]);
		if (!(ft_strcmp(t[i], "##start")) && t[i + 1] && is_room(t[i + 1]))
			set_start(t[i + 1], rooms);
		if (!(ft_strcmp(t[i], "##end")) && t[i + 1] && is_room(t[i + 1]))
			set_end(t[i + 1], rooms);
		i++;
	}
}
