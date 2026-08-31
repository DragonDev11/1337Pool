/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:13:40 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/27 13:47:20 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = ft_strlen(dest);
	if (size == 0)
		return (0);
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[j] && j < size - 1 - i)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char dest2[5] = "Hellojnjebndjwndjwnd";
	char src[5] = "!!!!!";	
	printf("%s\n", dest2);
	int ret = strlcat(dest2, src, sizeof(dest2) + sizeof(src) + 1);
	printf("%d\n%s\n", ret, dest2);
	return (0);
}
*/
