/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:03:21 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/18 12:43:56 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE
#endif
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char 	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *s1, const char *s2, size_t size);
#endif