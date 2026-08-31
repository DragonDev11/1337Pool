/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:12:51 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/24 15:18:00 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_base16[16] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_base16(char c, char str[2])
{
	unsigned char	uc;

	uc = (unsigned char)c;
	str[0] = g_base16[((int)uc / 16)];
	str[1] = g_base16[((int)uc % 16)];
}

int	is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	b16[2];

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_printable(str[i]))
		{
			to_base16(str[i], b16);
			ft_putchar('\\');
			ft_putchar(b16[0]);
			ft_putchar(b16[1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
