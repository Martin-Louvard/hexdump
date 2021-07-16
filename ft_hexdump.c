/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:40:36 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 11:16:41 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//attention, le vrai hexdump rajoute un saut de ligne en fin de fichier.
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

void	ft_print_line(t_line *line)
{
	if (ft_strcmp(line->previous, line->buffer))
	{
		ft_put_compteur_c(line->previous_counter);
		ft_print_hexa_c(line->hexa, line->buffer);
		ft_print_char(line->buffer);
		ft_strcpy(line->previous, line->buffer);
		line->same = 0;
	}
	else
	{
		if (!line->same)
			ft_putstr("*");
		line->same++;
	}
	if (line->same == 0 || line->same == 1)
		ft_putstr("\n");
	line->previous_counter = line->compteur;
}

void	ft_read_file(int fd, t_line *line)
{
	char	c;

	while (read(fd, &c, 1) > 0)
	{
		if (line->rest_c != 0)
		{
			line->rest[line->rest_c] = c;
			line->rest_c++;
		}
		else
			line->buffer[line->compteur % 16] = c;
		line->compteur++;
		if (line->rest_c == 16)
			ft_print_rest(line);
		else if (line->compteur % 16 == 0)
			ft_print_line(line);
	}
	ft_strncpy(line->rest, line->buffer, (line->compteur % 16), &line->rest_c);
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
		ft_print_rest(&line);
		ft_put_compteur_c(line.compteur);
		ft_putstr("\n");
	}
	//else
	//read stdin
	return (0);
}
