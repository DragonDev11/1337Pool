/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:48:29 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/27 16:24:44 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	g_this_global = 0;

void	this_function(int nb)
{
	if (nb < 0)
		return ;
	if (g_this_global < nb)
	{
		g_this_global++;
		printf("%d", g_this_global);
		this_function(nb);
	}else if (g_this_global < nb * 2 - 1){
		g_this_global++;
		printf("%d", nb + (nb - g_this_global));
	
		this_function(nb);
	}
	return ;
}

int main()
{
	this_function(100);
	return (0);
}
