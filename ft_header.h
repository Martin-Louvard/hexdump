/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:13:57 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/15 17:46:52 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <stdlib.h>
typedef struct s_line
{
	int		compteur;
	char	buffer[16];
	char	rest[16];
	char	previous[16];
	char	hexa[32];
	int		option;
}	t_line;
void	ft_putstr(char *str);
void	ft_puterr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstrerror(char *name, char *file int errno);
void	ft_zeros(t_line *line);
int		ft_c(int argc, char **argv);
#endif
