/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:40:36 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/15 17:47:08 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"


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
				ft_putstrerror(argv[0], argv[i], errno);
			i++;
		}
	}
	//else
		//read stdin
	return (0);
}
