/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:11:21 by iouardi           #+#    #+#             */
/*   Updated: 2021/11/24 22:53:08 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

# define HEX	"0123456789abcdef"

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putnbr(int n, int *i);
void	ft_putnbr_unsigned(unsigned int n, int *i);
void	ft_put_hex(unsigned int n, char x, int *i);
void	ft_put_p_hex(unsigned long n, int *i);
#endif