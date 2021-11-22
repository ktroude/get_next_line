/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:28:17 by ktroude           #+#    #+#             */
/*   Updated: 2021/11/18 16:47:50 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 40

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	*cut_line(char **str, int pos)
{
	char	*line;
    char    *save;
    int		i;
    
	i = 0;
	line = ft_substr(*str, 0, pos + 1);
	pos++;
	if (ft_strlen(*str + pos) > 0)
	{
        save = ft_strdup(*str + i);
        free(str);
        str = ft_strdup(save);
        free(save);
	}
	else
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*no_new_line(char **str)
{	
	char	*line;

	line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str = NULL;
	int			ret;
	int			pos;

	if (str)
	{
		pos = ft_strchr(str, '\n');
		if (pos != -1)
			return (cut_line(&str, pos));
	}
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0 && str == NULL)
			return (NULL);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		pos = ft_strchr(str, '\n');
		if (pos != -1)
			return (cut_line(&str, pos));
	}
	return (no_new_line(&str));
}
/*
int	main()
{
	int	fd;

	fd = open("coucou", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
}
*/
