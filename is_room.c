/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:07:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 16:04:11 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_coord(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_first(char *s)
{
	if (s[0] == '#' || s[0] == 'L')
		return (0);
	return (1);
}

int			is_room(char *s)
{
	char	**tab;
	int		i;
	int		res;

	i = 0;
	res = 1;
	tab = ft_strsplit(s, ' ');
	while (tab[i])
		i++;
	if (i != 3 || !check_first(tab[0]) || !check_coord(tab[1]) ||
		!check_coord(tab[2]))
		res = 0;
	ft_free_tab(tab);
	return (res);
}
