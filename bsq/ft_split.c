/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:35:28 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 09:43:48 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str && ft_is_in_string(*str, charset) != -1)
		str++;
	while (*str)
	{
		if (ft_is_in_string(*str, charset) == -1
			&& ft_is_in_string(*(str + 1), charset) != -1 && *(str + 1))
			count++;
		if (ft_is_in_string(*str, charset) == -1 && *(str + 1) == '\0')
		{
			count++;
			break ;
		}
		str++;
	}
	return (count);
}

char	*ft_this_function(char *str, char *to_find, int *word_length)
{
	int	i;

	i = 0;
	while (*str && ft_is_in_string(*str, to_find) != -1)
		str++;
	while (*(str + i))
	{
		if (ft_is_in_string(*(str + i), to_find) != -1)
			break ;
		i++;
	}
	*word_length = i;
	return (str + i);
}

char	*ft_strndup(char *src, unsigned int n)
{
	char			*dup;
	unsigned int	i;

	dup = (char *)malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**split;
	int		i;
	int		word_length;

	words = ft_count_words(str, charset);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		str = ft_this_function(str, charset, &word_length);
		if (word_length <= 0)
			continue ;
		str -= word_length;
		split[i] = ft_strndup(str, word_length);
		if (!split[i])
			return (NULL);
		str += word_length;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
#include <stdio.h>

int main()
{
	char **split = ft_split("Hello world,Test;Hi", NULL);
	for (int i=0; i<3; i++)
		printf("%s\n", split[i]);
	return (0);
}
*/
