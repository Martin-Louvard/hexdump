/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:20:11 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 11:01:52 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstrerror(char *name, char *file)
{
	ft_puterr(basename(name));
	ft_puterr(": ");
	ft_puterr(file);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}
