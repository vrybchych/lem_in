/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 09:06:08 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/25 10:09:31 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**      ants[i][0] - current rooom
**      ants[i][1] - current route
**      riu - route in use
*/

static void	ft_free_ants(int **ants)
{
	int		i;

	i = 0;
	while (i < g_ants)
	{
		free(ants[i]);
		i++;
	}
	free(ants);
}

static void	ft_print(int ant_nb, int room_index, char **rooms)
{
	ft_putchar('L');
	ft_putnbr(ant_nb + 1);
	ft_putchar('-');
	ft_putstr(rooms[room_index]);
	ft_putchar(' ');
}

static int	**create_ants_tab(void)
{
	int		**ants;
	int		i;

	i = 0;
	ants = (int**)malloc(sizeof(int*) * g_ants);
	while (i < g_ants)
	{
		ants[i] = (int*)malloc(sizeof(int) * 2);
		ants[i][0] = -1;
		ants[i][1] = -1;
		i++;
	}
	return (ants);
}

void		move(int **routes, char **rooms)
{
	int		**ants;
	int		i;
	int		riu;

	ants = create_ants_tab();
	while (ants[g_ants - 1][0] != g_end)
	{
		i = 0;
		riu = -1;
		while (i < g_ants)
		{
			if (ants[i][0] != g_end)
			{
				ants[i] = set_next_step(ants[i], &riu, routes, i);
				if (riu != -2)
					ft_print(i, ants[i][0], rooms);
			}
			if (riu == -2)
				break ;
			i++;
		}
		ft_putchar('\n');
	}
	ft_free_ants(ants);
}
