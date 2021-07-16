/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:13:57 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/16 11:01:36 by malouvar         ###   ########.fr       */
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
	int		previous_counter;
	char	buffer[17];
	char	rest[17];
	char	previous[17];
	char	hexa[50];
	int		option;
	int		same;
	int		rest_c;
}	t_line;
void	ft_putstr(char *str);
void	ft_puterr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstrerror(char *name, char *file);
void	ft_zeros(t_line *line);
int		ft_c(int argc, char **argv);
void	ft_put_compteur_c(int nbr);
void	ft_print_hexa_c(char *hexa, char *buffer);
void	ft_strcpy(char *dest, char *src);
void	ft_strncpy(char *dest, char *src, unsigned int n, int *rest_c);
void	ft_print_rest(t_line *line);
void	ft_print_hexa_rest_c(char *buffer, int	count);
#endif
