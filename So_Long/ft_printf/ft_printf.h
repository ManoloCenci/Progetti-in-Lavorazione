/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:26:07 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/13 15:43:30 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(char c);
int	ft_printstring(char *str);
int	ft_printnumb(int nb);
int	ft_printunsigned(unsigned int nb);
int	ft_printperc(void);
int	ft_printhex(unsigned long n, char *format);
int	ft_printpointer(unsigned long nb, char *format);
#endif
