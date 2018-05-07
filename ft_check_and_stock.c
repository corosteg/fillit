/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_stock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:48:45 by corosteg          #+#    #+#             */
/*   Updated: 2017/03/21 15:48:38 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_lgn(char *str, int i, int a, int b)
{
	while (str[i])
	{
		a++;
		b++;
		if (b == 21)
			a = 0;
		if (a == 5 && str[i] != '\n')
			return (0);
		if (a == 5)
			a = 0;
		if (b == 21 && str[i] != '\n' && str[i] != '\0')
			return (0);
		if (b == 21)
			b = 0;
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n' && str[i] != '\0')
			return (0);
		if (str[i + 1] == '\0' && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
			return (0);
		if (str[i + 1] == '\0' && b + 1 != 21)
			return (0);
		i++;
	}
	return (1);
}

char		**ft_tabcpy(char **tab, int b)
{
	int		x;
	int		y;
	char	**tab2;

	x = 0;
	y = 0;
	tab2 = (char**)malloc(sizeof(char*) * 5);
	tab2[0] = ft_strdup(tab[b * 4 + 0]);
	tab2[1] = ft_strdup(tab[b * 4 + 1]);
	tab2[2] = ft_strdup(tab[b * 4 + 2]);
	tab2[3] = ft_strdup(tab[b * 4 + 3]);
	ft_modif4(tab2);
	return (tab2);
}

t_list		*ft_stock(t_list *list, char **tab, int b)
{
	t_list *tmp;

	tmp = list;
	if (b == 0)
	{
		list = (t_list*)malloc(sizeof(t_list));
		list->pcs = tab;
		list->letter = (b + 'A');
		list->next = NULL;
		return (list);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_list*)malloc(sizeof(t_list));
		tmp->next->pcs = tab;
		tmp->next->letter = (b + 'A');
		tmp->next->next = NULL;
	}
	return (list);
}

t_list		*ft_check_pcs(char *str, int a, int b, int y)
{
	char	**tab;
	char	**tab2;
	t_list	*list;

	tab = ft_strsplit(str, '\n');
	while (tab[y++])
	{
		a++;
		if (a == 4)
		{
			tab2 = ft_tabcpy(tab, b);
			ft_modif(tab2, b, 0, 10);
			if (ft_valid_pcs(tab2, 0, 0, 0) == 0)
				return (0);
			list = ft_stock(list, tab2, b);
			b++;
			a = 0;
		}
	}
	list->nb = b;
	return (list);
}

t_list		*ft_check_and_stock(char *str)
{
	int		i;
	int		fd;
	t_list	*list;
	char	buf[600];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	i = read(fd, buf, 600);
	if (i > 580)
		return (0);
	if (ft_check_first_n(buf) == 0)
		return (0);
	if (ft_check_lgn(buf, 0, 0, 0) == 0)
		return (0);
	if ((list = ft_check_pcs(buf, 0, 0, 0)) == 0)
		return (0);
	return (list);
}
