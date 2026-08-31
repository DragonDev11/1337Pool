/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:43:40 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 09:37:48 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(ft_strlen(src) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		if (stock[i].copy == NULL)
		{
			while (i > 0)
				free(stock[--i].copy);
			free(stock);
			return (NULL);
		}
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%lu\n", sizeof(t_stock_str));
	t_stock_str *tab = ft_strs_to_tab(argc, argv);
	for(int i=0; i<argc; i++)
		printf("%d, %s, %s\n", tab[i].size, tab[i].str, tab[i].copy);
	return (0);
}
*/
