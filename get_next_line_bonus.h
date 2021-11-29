/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:18:07 by ilefhail          #+#    #+#             */
/*   Updated: 2021/11/27 21:18:09 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*ft_strdup( char *src);
int		ft_strlen(const char *str);

#endif
