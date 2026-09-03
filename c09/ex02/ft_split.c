/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:52:23 by mhmichi           #+#    #+#             */
/*   Updated: 2026/09/02 02:34:58 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	ft_str_contains(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (i - 1);
	return (-1);
}

int	cw(char *str, char *charset, char **start)
{
	int	count;

	count = 0;
	while (ft_str_contains(*str, charset) != -1 && *str)
		str++;
	(*start) = str;
	while (*str)
	{
		if (ft_str_contains(*str, charset) == -1
			&& ft_str_contains(*(str + 1), charset) != -1
			&& *(str + 1))
			count++;
		if (ft_str_contains(*str, charset) == -1 && *(str + 1) == '\0')
		{
			count++;
			break ;
		}
		str++;
	}
	return (count);
}

char	*ft_strstr_plus(char *str, char *charset, int *word_len)
{
	int	i;

	i = 0;
	while (*str && ft_str_contains(*str, charset) != -1)
		str++;
	while (*(str + i))
	{
		if (ft_str_contains(*(str + i), charset) != -1)
			break ;
		i++;
	}
	*word_len = i;
	return (str + i);
}

char	*ft_strndup(char *src, unsigned int n)
{
	char			*dup;
	unsigned int	i;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i <= n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		size;
	int		i;
	int		len;

	size = cw(str, charset, &str) + 1;
	split = (char **)malloc(sizeof(char *) * size);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		str = ft_strstr_plus(str, charset, &len);
		if (len <= 0)
			continue ;
		str -= len;
		split[i] = ft_strndup(str, len - 1);
		if (!split[i])
			return (NULL);
		str += len + 1;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
#include <stdio.h>

int main()
{
	char **split = ft_split(",,,,Hello      Earth    ;I;Love; you; <3", " ,;");
	while (*split)
	{
		printf("%s\n", *(split));
		split++;
	}
	return (0);
}
*/
