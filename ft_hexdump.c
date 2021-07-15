/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:40:36 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/15 17:09:32 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_line
{
	int		compteur;
	char	buffer[16];
	char	rest[16];
	char	previous[16];
	char	hexa[32];
	int		option;
} t_line;

int	ft_c(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] == "-C")
			return (1);
		i++;
	}
	return (0);
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
		(*line).previous ='\0';
		(*line).hexa[i] = '\0';
		i++;
	}
	while (i < 32)
	{
		(*line).hexa[i] = '\0';
		i++;
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
		while (i < argc)
		{
			if (argv[i] == "-C")
				i++;
			fd = open(argv[i], O_RDONLY);
			if (fd != -1)
				ft_read_file(fd, line);
			else
				ft_putstrerror(errno)
			i++;
		}
	}
	//else
		//read stdin
	return (0);
}
