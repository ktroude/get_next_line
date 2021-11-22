/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:07:05 by ktroude           #+#    #+#             */
/*   Updated: 2021/11/18 16:09:00 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!(str))
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1++;
	}
	free (s1);
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	s2 = malloc (sizeof(char) * i + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		return (-1);
	return (i);
}

char	*ft_memmove(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (len--)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
