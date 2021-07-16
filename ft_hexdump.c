/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:40:36 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 13:21:23 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

void	ft_print_line_c(t_line *line)
{
	if (ft_strcmp(line->previous, line->buffer))
	{
		ft_put_compteur_c(line->previous_counter);
		ft_print_hexa_c(line->hexa, line->buffer);
		ft_print_char_c(line->buffer);
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

void	ft_print_line(t_line *line)
{
	if (ft_strcmp(line->previous, line->buffer))
	{
		ft_put_compteur(line->previous_counter);
		ft_print_hexa(line->hexa, line->buffer);
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

int	main(int argc, char **argv)
{
	t_line	line;

	ft_zeros(&line);
	line.option = ft_c(argc, argv);
	if ((line.option && argc > 2) || (!line.option && argc > 1))
	{
		if (line.option)
			ft_open_files_c(line, argc, argv, 1);
		else
			ft_open_files(line, argc, argv, 1);
	}
	//else
	//read stdin
	return (0);
}
