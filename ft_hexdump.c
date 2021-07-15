/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:40:36 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/15 21:32:50 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

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

void	ft_read_file(int fd, t_line *line)
{
	char	c;
	int		ok;

	while (read(fd, &c, 1) > 0)
	{
		line->buffer[line->compteur % 16] = c;
		line->compteur++;
		if (line->compteur % 16 == 0)
		{	
			if (ft_strcmp(line->previous, line->buffer))
			{
				ft_print_hexa_c(line->hexa, line->buffer);
				ft_print_char(line->buffer);
				ft_strcpy(line->previous, line->buffer);
				ok = 1;
			}
			else
			{
				ft_putstr("*");
				ok = 0;
			}
			ft_putstr("\n");
			if (ok)
			ft_put_compteur_c(line->compteur);
		}
	}
}

int	main(int argc, char **argv)
{
	t_line	line;
	int		i;
	int		fd;

	ft_zeros(&line);
	line.option = ft_c(argc, argv);
	if ((line.option && argc > 2) || (!line.option && argc > 1))
	{
		i = 1;
		ft_put_compteur_c(line.compteur);
		while (i < argc)
		{
			if (!ft_strcmp(argv[i], "-C"))
				i++;
			fd = open(argv[i], O_RDONLY);
			if (fd != -1)
				ft_read_file(fd, &line);
			else
				ft_putstrerror(argv[0], argv[i]);
			i++;
		}
	}
	//else
	//read stdin
	return (0);
}
