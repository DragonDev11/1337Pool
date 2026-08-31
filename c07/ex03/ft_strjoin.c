/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:33:43 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 09:44:46 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*this_function(int size, char **strs, char *sep, int length)
{
	char	*this_string;
	int		i;
	int		j;
	int		k;

	this_string = (char *)malloc(length + ((size - 1) * ft_strlen(sep)));
	if (this_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
			this_string[j++] = strs[i][k++];
		if (i < size - 1)
		{
			k = 0;
			while (sep[k])
				this_string[j++] = sep[k++];
		}
		i++;
	}
	this_string[j] = '\0';
	return (this_string);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*a_very_long_string;
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (i < size)
		length += ft_strlen(strs[i++]);
	length++;
	a_very_long_string = NULL;
	if (size > 0)
		a_very_long_string = this_function(size, strs, sep, length);
	else if (size == 0)
		a_very_long_string = (char *)malloc(1);
	if (a_very_long_string == NULL)
		return (NULL);
	if (size == 0)
		a_very_long_string[0] = '\0';
	return (a_very_long_string);
}
/*
int main()
{
	char *strs[5] = {"Hello", "Hi", "Banana", "", "sep"};
	printf("%s\n", ft_strjoin(sizeof(strs)/sizeof(strs[0]), strs, " / "));
	return 0;
}
*/
