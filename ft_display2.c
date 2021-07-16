/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:16:13 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 13:15:20 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
void	ft_print_hexa(char *hexa, char *buffer)
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
		i++;
	}
	if (i < 16)
		while (j < 50)
			hexa[j++] = ' ';
	write(1, " ", 1);
	write(1, hexa, 47);
}

void	ft_print_hexa_rest(char *buffer, int	count)
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
		i++;
	}
	while (j < 50)
		hexa[j++] = ' ';
	write(1, " ", 1);
	write(1, hexa, 47);
}

void	ft_put_compteur(int nbr)
{
	char	tab[7];
	char	*base;
	int		i;

	i = 6;
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
	write(1, tab, 7);
}

void	ft_print_rest(t_line *line)
{
	ft_put_compteur(line->previous_counter);
	ft_print_hexa_rest(line->rest, line->rest_c);
	write(1, "\n", 1);
	line->rest_c = 0;
	ft_strcpy(line->previous, line->rest);
	line->same = 0;
}
