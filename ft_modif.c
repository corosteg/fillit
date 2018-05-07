/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:20:03 by paoroste          #+#    #+#             */
/*   Updated: 2016/12/02 21:26:37 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_modif2(char **tab)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == '#')
			{
				while (tab[y][x] == '#')
					x++;
				tab[y][x] = '\0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (tab);
}

char		**ft_modif3(char **tab, int b)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == '#')
				tab[y][x] = (b + 'A');
			x++;
		}
		x = 0;
		y++;
	}
	return (tab);
}

char		**ft_modif(char **tab, int b, int i, int c)
{
	int		x;

	x = 0;
	while (i < 4)
	{
		while (tab[i][x])
		{
			if (tab[i][x] == '#' && x < c)
				c = x;
			x++;
		}
		i++;
		x = 0;
	}
	i = 0;
	while (i < 4 && tab[i][0] != '\0')
	{
		tab[i] = ft_strdup(&tab[i][c]);
		i++;
	}
	tab = ft_modif2(tab);
	tab = ft_modif3(tab, b);
	return (tab);
}
