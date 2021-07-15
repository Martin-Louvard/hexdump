/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:44:38 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/15 21:27:34 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i < 16 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	ft_zeros(t_line *line)
{
	int	i;

	i = 0;
	(*line).compteur = 0;
	while (i < 16)
	{
		(*line).buffer[i] = '\0';
		(*line).rest[i] = '\0';
		(*line).previous[i] = '\0';
		(*line).hexa[i] = '\0';
		i++;
	}
	while (i < 32)
	{
		(*line).hexa[i] = '\0';
		i++;
	}
}

int	ft_c(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-C"))
			return (1);
		i++;
	}
	return (0);
}
