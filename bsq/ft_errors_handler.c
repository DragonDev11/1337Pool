/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:41:40 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 17:43:02 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_errors_handler.h"

void	free_double_pointer(void **p, unsigned int elements)
{
	int	i;

	i = 0;
	while (i < elements)
		free(p[i++]);
	free(p);
}
