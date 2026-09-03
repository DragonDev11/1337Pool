/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:08:12 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/25 17:33:43 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (ft_strlen(to_find) == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j])
		{
			if (to_find[j] == '\0')
				return (str + i - j);
			j++;
			i++;
		}
		i = i - j + 1;
	}
	return (0);
}
