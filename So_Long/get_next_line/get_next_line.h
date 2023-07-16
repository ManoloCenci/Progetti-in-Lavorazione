/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:23:21 by dmarcian          #+#    #+#             */
/*   Updated: 2023/07/14 15:25:01 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlenn(char *str);
char	*get_next_line(int fd);
char	*ft_new(char *res);
char	*ft_putline(char *res);
char	*ft_strjoinn(char *res, char *temp);
char	*ft_search(char *s);
char	*ft_read(int fd, char *res);
#endif
