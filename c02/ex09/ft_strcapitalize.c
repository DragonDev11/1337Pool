/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 09:27:12 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/20 12:27:26 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_capital(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	capitalize_condition(char prev, char c)
{
	return (is_alpha(c) && !is_capital(c) && !is_num(prev) && !is_alpha(prev));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_capital(str[i]))
			str[i] += 32;
		i++;
	}
	i = 1;
	while (str[i] != '\0')
	{
		if (capitalize_condition(str[i - 1], str[i]))
			str[i] -= 32;
		i++;
	}
	if (is_alpha(str[0]) && !is_capital(str[0]))
		str[0] -= 32;
	return (str);
}
