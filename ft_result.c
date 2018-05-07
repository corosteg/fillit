/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:24:52 by corosteg          #+#    #+#             */
/*   Updated: 2016/12/02 22:00:12 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_result(t_list *list)
{
	char	**final;
	int		i;

	i = list->nb / 2;
	final = NULL;
	while (final == NULL)
	{
		i++;
		final = ft_map_gen(i, 0);
		final = ft_map_check(list, list, final);
	}
	return (final);
}
