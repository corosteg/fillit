/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_pcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:58:15 by corosteg          #+#    #+#             */
/*   Updated: 2016/12/02 21:58:19 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ultimate_verif(char **tab)
{
	if ((tab[0][0] >= 'A' && tab[0][0] <= 'Z') &&
		(tab[0][1] >= 'A' && tab[0][1] <= 'Z') &&
		(tab[1][0] >= 'A' && tab[1][0] <= 'Z') &&
		(tab[1][0] >= 'A' && tab[1][1] <= 'Z'))
		return (1);
	else
		return (0);
}

int		last_verif(int i, char **tab)
{
	if (i == 6)
		return (1);
	if (i == 8 && ultimate_verif(tab) == 1)
		return (1);
	return (0);
}

int		ft_valid_pcs(char **tab, int y, int x, int count)
{
	while (y < 4)
	{
		while (tab[y][x])
		{
			if (tab[y][x] >= 'A' && tab[y][x] <= 'Z')
			{
				if (((y - 1) >= 0) && ((tab[y - 1][x] >= 'A')
					&& (tab[y - 1][x] <= 'Z')))
					count++;
				if ((y < 3) && ((tab[y + 1][x] >= 'A')
					&& (tab[y + 1][x] <= 'Z')))
					count++;
				if (((x - 1) >= 0) && ((tab[y][x - 1] >= 'A')
					&& (tab[y][x - 1] <= 'Z')))
					count++;
				if (tab[y][x + 1] >= 'A' && tab[y][x + 1] <= 'Z')
					count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (last_verif(count, tab));
}
