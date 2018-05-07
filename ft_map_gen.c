/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:38:53 by corosteg          #+#    #+#             */
/*   Updated: 2016/12/02 20:52:34 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map_gen(int i, int x)
{
	char	**map;
	int		y;

	y = 0;
	map = (char**)malloc(sizeof(char*) * i + 1);
	map[i + 1] = 0;
	while (y < i)
	{
		map[y] = (char*)malloc(sizeof(char) * (i + 1));
		while (x < i)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		x = 0;
		y++;
	}
	return (map);
}
