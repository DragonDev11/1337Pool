/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:30:11 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/18 23:01:10 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_base16[16] = "0123456789abcdef";

void	print_char(char c)
{
	if ((c >= ' ' && c <= '~'))
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	to_base16(unsigned long l, char b16[], int size)
{
	int	i;

	i = size - 1;
	while (l / 16 > 0)
	{
		b16[i--] = g_base16[(l % 16)];
		l /= 16;
	}
	b16[i--] = g_base16[(l % 16)];
	while (i >= 0)
	{
		b16[i--] = g_base16[0];
	}
}

void	*print_mem_content_char(void *addr, unsigned int end)
{
	unsigned int	k;

	k = 0;
	write(1, " ", 1);
	while (k++ < 16 - end)
		print_char(*((char *)addr++));
	return (addr);
}

void	*print_mem_content(void *addr, unsigned int *i,
		unsigned int end,
		char b16_2[2])
{
	unsigned int	k;
	int				j;
	unsigned char	c;

	k = 0;
	while (k < 16)
	{
		if (k++ % 2 == 0)
			write(1, " ", 1);
		if (k <= 16 - end)
		{
			c = (unsigned char)*((char *)addr++);
			to_base16((unsigned int)c, b16_2, 2);
			j = 0;
			while (j < 2)
				print_char(b16_2[j++]);
			(*i)++;
		}
		else
		{
			write(1, "  ", 2);
			addr++;
		}
	}
	return (print_mem_content_char(addr - 16, end));
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	mem_addr_long;
	char			b16_16[16];
	char			b16_2[2];
	unsigned int	i;
	int				j;

	if (size <= 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mem_addr_long = (unsigned long)addr;
		to_base16(mem_addr_long, b16_16, 16);
		j = 0;
		while (j < 16)
			write(1, &b16_16[j++], 1);
		write(1, ":", 1);
		if (i < (unsigned int)(size / 16)*16)
			addr = print_mem_content(addr, &i, 0, b16_2);
		else
			addr = print_mem_content(addr, &i, 16 - (size % 16), b16_2);
		write(1, "\n", 1);
	}
	return (addr - size);
}
