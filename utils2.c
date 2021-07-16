/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:44:38 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 11:01:34 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

void	ft_strncpy(char *dest, char *src, unsigned int n, int *rest_c)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	*rest_c = i;
}

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
	(*line).same = 0;
	(*line).previous_counter = 0;
	(*line).rest_c = 0;
	while (i < 17)
	{
		(*line).buffer[i] = '\0';
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
