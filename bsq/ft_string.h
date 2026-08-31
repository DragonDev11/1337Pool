/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:10:53 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 14:14:29 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_str_contains(char c, char *str);
int	ft_count_words(char *str, char *charset);
char	*ft_strstr(char *str, char *to_find, int *word_length);
char	*ft_strndup(char *src, unsigned int n);
char	**ft_split(char *str, char *charset);

#endif
