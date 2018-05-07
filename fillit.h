/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:09 by corosteg          #+#    #+#             */
/*   Updated: 2016/12/20 18:50:30 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

char				**ft_modif4(char **tab);
char				**ft_yes_is_possible(char **map, int y, int x, char **pcs);
void				print_pcs_list(t_list *list);
int					ft_check_first_n(char *str);
t_list				*ft_check_and_stock(char *str);
int					ft_cpy_if_possible(char **map, int y, int x, char **pcs);
int					ft_valid_pcs(char **tab, int y, int x, int count);
char				**ft_modif3(char **tab, int b);
char				**ft_modif(char **tab, int b, int i, int c);
void				ft_print(char **tab);
char				**ft_result(t_list *list);
char				**ft_map_check(t_list *tmp, t_list *list, char **map);
char				**ft_map_gen(int i, int x);

#endif
