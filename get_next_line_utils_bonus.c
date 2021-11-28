/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:17:45 by ilefhail          #+#    #+#             */
/*   Updated: 2021/11/27 21:17:47 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	char		*reslt;
	int			i;

	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == c)
		{
			reslt = ft_strdup(&str[i + 1]);
			free(str);
			return (reslt);
		}
		i++;
	}
	free(str);
	return (NULL);
}

char	*ft_strdup(char	*src)
{
	char	*pstr;
	int		i;

	i = 0;
	pstr = malloc((ft_strlen(src) + 1) * sizeof (char));
	if (pstr == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		pstr[i] = src[i];
		i++;
	}
	pstr[i] = '\0';
	return (pstr);
}
