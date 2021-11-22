/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:36:55 by ktroude           #+#    #+#             */
/*   Updated: 2021/11/18 16:09:11 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strdup(const char *s1);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*no_new_line(char **str);
char	*cut_line(char **str, int pos);
int		ft_strchr(char *s, char c);
char	*ft_memmove(char *dst, char *src, int len);

#endif
