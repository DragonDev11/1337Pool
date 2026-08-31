/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:24:46 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/25 16:38:42 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i] && i < nb)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[5] = "Mine";
	char dest2[10] = "Hell";
	printf("%s\n", strncat(str, "Hi", 2));
	printf("%s\n", ft_strncat(dest2, "Hi", 2));
	return (0);
}
*/
