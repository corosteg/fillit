/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:09:56 by corosteg          #+#    #+#             */
/*   Updated: 2017/03/21 15:48:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	char	**map;

	if (argc != 2)
	{
		ft_putstr("usage : fillit input_file\n");
		return (0);
	}
	if ((list = ft_check_and_stock(argv[1])) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	map = ft_result(list);
	ft_print(map);
	return (0);
}
