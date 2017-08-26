/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:17:11 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/26 09:54:42 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

int			g_rooms_count;
int			g_ants;
int			g_start;
int			g_end;

void		ft_error(void);

/*
**                          A L G O R I T H M
*/

int			**add_route(int **routes, int *route);
int			**create_routes_tab(int size);
int			*find_route(int **status, int **links);
void		move(int **routes, char **rooms);
int			*set_next_step(int *ant, int *riu, int **routes, int i);
int			**set_routes(int **links);
int			**set_route_status(int **links, int **route, int no_way);

/*
**                             R E A D E R
*/

void		check_valid(char **tab, char **rooms);
void		ft_free_tab(char **tab);
char		**get_rooms(char **tab);
int			is_room(char *s);
char		**reader();
void		set_globals(char **t, char **rooms);
int			**set_links(char **tab, char **rooms);

#endif
