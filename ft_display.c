/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:09:57 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 11:24:14 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
void	ft_print_hexa_c(char *hexa, char *buffer)
{
	unsigned int		i;
	int					j;
	char				*base;

	base = "0123456789abcdef";
	i = 0;
	j = 0;
	while (i < 16)
	{
		hexa[j++] = base[((unsigned char)buffer[i]) / 16];
		hexa[j++] = base[((unsigned char)buffer[i]) % 16];
		if ((j + 1) % 3 == 0)
			hexa[j++] = ' ';
		if ((j + 1) / 25 == 1)
			hexa[j++] = ' ';
		i++;
	}
	if (i < 16)
		while (j < 50)
			hexa[j++] = ' ';
	write(1, "  ", 2);
	write(1, hexa, 49);
	write(1, " ", 1);
}

void	ft_print_hexa_rest_c(char *buffer, int	count)
{
	int					i;
	int					j;
	char				*base;
	char				hexa[50];

	base = "0123456789abcdef";
	i = 0;
	j = 0;
	while (i < count)
	{
		hexa[j++] = base[((unsigned char)buffer[i]) / 16];
		hexa[j++] = base[((unsigned char)buffer[i]) % 16];
		if ((j + 1) % 3 == 0)
			hexa[j++] = ' ';
		if ((j + 1) / 25 == 1)
			hexa[j++] = ' ';
		i++;
	}
	while (j < 50)
		hexa[j++] = ' ';
	write(1, "  ", 2);
	write(1, hexa, 49);
	write(1, " ", 1);
}

void	ft_put_compteur_c(int nbr)
{
	char	tab[8];
	char	*base;
	int		i;

	i = 7;
	base = "0123456789abcdef";
	while (i >= 0)
	{
		if (nbr > 0)
		{
			tab[i] = base[nbr % 16];
			nbr = nbr / 16;
		}
		else
			tab[i] = '0';
		i--;
	}
	write(1, tab, 8);
}

void	ft_print_char(char *str)
{
	unsigned int	i;

	i = 0;
	write(1, "|", 1);
	while (i < 16 && str[i])
	{
		if (str[i] > 31 && str[i] < 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	ft_print_rest(t_line *line)
{
	int	i;

	ft_put_compteur_c(line->previous_counter);
	ft_print_hexa_rest_c(line->rest, line->rest_c);
	i = 0;
	write(1, "|", 1);
	while (i < line->rest_c)
	{
		if (line->rest[i] > 31 && line->rest[i] < 127)
			write(1, &line->rest[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	if (line->rest[i] == 10)
		write(1, ".", 1);
	write(1, "|\n", 2);
	line->rest_c = 0;
	ft_strcpy(line->previous, line->rest);
	line->same = 0;
}
