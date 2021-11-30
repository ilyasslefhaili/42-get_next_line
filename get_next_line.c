/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:17:30 by ilefhail          #+#    #+#             */
/*   Updated: 2021/11/24 00:17:32 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchar(char *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		s = ft_calloc(1, i + 1);
	else
		s = ft_calloc(1, i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = str[i];
	return (s);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*done(char *chkra, char *buf, int fd)
{
	int	i;
	int	rd;

	i = 0;
	while (buf[i] != '\n')
	{
		i = 0;
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buf[rd] = '\0';
		chkra = ft_strjoin(chkra, buf);
		while (buf[i] != '\n' && buf[i])
			i++;
	}
	return (chkra);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*chkra;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (chkra == NULL)
		chkra = ft_strdup("");
	buf = ft_calloc(1, BUFFER_SIZE + 1);
	chkra = done(chkra, buf, fd);
	free(buf);
	if (chkra[0] == '\0')
	{
		free(chkra);
		chkra = NULL;
		return (NULL);
	}
	s = ft_strchar(chkra, '\n');
	chkra = ft_strchr(chkra, '\n');
	return (s);
}
