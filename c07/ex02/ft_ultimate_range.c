/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:20:07 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/30 10:52:56 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i + min < max)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>

int main()
{	
	int	tab[] = {0};
	int	*p = tab;
	ft_ultimate_range(&p, 0, 100);
	for (int i=0; i<100; i++)
		printf("%d\n", p[i]);
	return (0);
}
*/
