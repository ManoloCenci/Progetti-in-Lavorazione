/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:34:38 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/03 10:54:50 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
void	*ft_memset_get(void *b, int c, size_t len);
char	*ft_strdup_get(char *s1);
char	*ft_strchr_get(char *s, char c);
void	*ft_calloc_get(size_t count, size_t size);
size_t	ft_strlen_get(const char *str);
#endif
