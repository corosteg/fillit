/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:38:26 by corosteg          #+#    #+#             */
/*   Updated: 2016/12/09 18:54:19 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_pcs_remove(char c, char **map)
{
	int				x;
	int				y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char		**ft_map_check(t_list *tmp, t_list *list, char **map)
{
	int				x;
	int				y;
	char			**tab;

	y = 0;
	if (tmp == NULL)
		return (map);
	tab = NULL;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_cpy_if_possible(map, y, x, tmp->pcs) == 1)
				tab = ft_map_check(tmp->next, list,
					ft_yes_is_possible(map, y, x, tmp->pcs));
			if (tab != NULL)
				return (tab);
			map = ft_pcs_remove(tmp->letter, map);
			x++;
		}
		y++;
	}
	return (NULL);
}
