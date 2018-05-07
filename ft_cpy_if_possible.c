/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_if_possible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:43:05 by corosteg          #+#    #+#             */
/*   Updated: 2016/12/16 17:56:52 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			cpy_2(int *tab, char **map, char **pcs)
{
	while (pcs[0][tab[1]] && tab[5] != 0)
	{
		if (pcs[tab[0]][tab[1]] != '.' && map[tab[4] + tab[0]][tab[3] -
			tab[5] + tab[1]] == '.')
			tab[2]++;
		tab[1]++;
	}
	tab[1] = 0;
	while (pcs[tab[0]] && map[tab[4] + tab[0]])
	{
		while (pcs[tab[0]][tab[1]] && map[tab[4] +
			tab[0]][tab[3] - tab[5] + tab[1]])
		{
			if ((tab[0] >= 1 && tab[5] != 0) && (map[tab[4] + tab[0]][tab[3] -
				tab[5] + tab[1]] == '.' && pcs[tab[0]][tab[1]] != '.'))
				tab[2]++;
			else if (map[tab[4] + tab[0]][tab[3] + tab[1]] == '.' &&
				pcs[tab[0]][tab[1]] != '.' && tab[5] == 0)
				tab[2]++;
			tab[1]++;
		}
		tab[1] = 0;
		tab[0]++;
	}
	return (tab[2]);
}

int					ft_cpy_if_possible(char **map, int y, int x, char **pcs)
{
	int	a;
	int b;
	int count;
	int	tab[6];
	int retour;

	a = 0;
	b = 0;
	retour = 0;
	count = 0;
	tab[0] = a;
	tab[1] = b;
	tab[2] = count;
	tab[3] = x;
	tab[4] = y;
	tab[5] = retour;
	while (pcs[0][a++] == '.')
		tab[5]++;
	if (tab[5] > tab[3])
		return (0);
	if (cpy_2(tab, map, pcs) == 4)
		return (1);
	else
		return (0);
}
