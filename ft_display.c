/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:09:57 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/15 20:54:24 by malouvar         ###   ########.fr       */
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
	write(1, hexa, 50);
	write(1, "  ", 2);
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
	write(1, "  ", 2);
}
