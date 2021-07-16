/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:19:33 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 13:20:14 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_read_file_c(int fd, t_line *line)
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
			ft_print_rest_c(line);
		else if (line->compteur % 16 == 0)
			ft_print_line_c(line);
	}
	ft_strncpy(line->rest, line->buffer, (line->compteur % 16), &line->rest_c);
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

void	ft_open_files_c(t_line line, int argc, char **argv, int i)
{
	int	fd;

	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-C"))
			i++;
		fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{
			line.opened++;
			ft_read_file_c(fd, &line);
		}
		else
			ft_putstrerror(argv[0], argv[i]);
		i++;
	}
	if (line.opened != 0)
	{
		ft_print_rest_c(&line);
		ft_put_compteur_c(line.compteur);
		ft_putstr("\n");
	}
	else
		ft_print_badfd(argv[0], argv[i - 1]);
}

void	ft_open_files(t_line line, int argc, char **argv, int i)
{
	int	fd;

	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{
			line.opened++;
			ft_read_file(fd, &line);
		}
		else
			ft_putstrerror(argv[0], argv[i]);
		i++;
	}
	if (line.opened != 0)
	{
		ft_print_rest(&line);
		ft_put_compteur(line.compteur);
		ft_putstr("\n");
	}
	else
		ft_print_badfd(argv[0], argv[i - 1]);
}
