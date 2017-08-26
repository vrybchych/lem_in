/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:32:19 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/26 10:14:12 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*ft_add_line(char *s, char *line)
{
	char*str;

	if (!s)
		str = ft_strdup(line);
	else
	{
		str = ft_strjoin(s, line);
		free(s);
	}
	str = ft_strjoin(str, "\n");
	return (str);
}

char		**reader(void)
{
	char	*s;
	char	*line;
	char	**tab;

	s = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!line[0])
		{
			if (s)
				free(s);
			ft_error();
		}
		s = ft_add_line(s, line);
		free(line);
	}
	if (!s)
		ft_error();
	tab = ft_strsplit(s, '\n');
	return (tab);
}
