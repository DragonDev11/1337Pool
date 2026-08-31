/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:19:29 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/25 16:18:21 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char dest[4] = "Hell";
	printf("%s\n", strcat(dest, "Hi"));
	char dest2[4] = "Hell";
	printf("%s\n", ft_strcat(dest2, "Hi"));
	return (0);
}
*/
