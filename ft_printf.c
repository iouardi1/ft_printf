/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:16:33 by iouardi           #+#    #+#             */
/*   Updated: 2021/11/29 02:45:28 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_type(const char format, va_list arg, int *comp)
{
	if (format == '%')
		*comp += ft_putchar('%');
	else if (format == 'c')
		*comp += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		*comp += ft_putstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(arg, int), comp);
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(arg, unsigned int), comp);
	else if (format == 'x' || format == 'X' || format == 'p')
	{
		if (format == 'p')
		{
			*comp += ft_putstr("0x");
			ft_put_p_hex(va_arg(arg, unsigned long), comp);
		}
		else
			ft_put_hex(va_arg(arg, unsigned int), format, comp);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list			arg;
	int				size;
	int				comp;

	size = 0;
	comp = 0;
	va_start(arg, format);
	while (format[size])
	{
		if (format[size] == '%')
		{
			size++;
			format_type(format[size], arg, &comp);
		}
		else
			comp += ft_putchar(format[size]);
		size++;
	}
	va_end(arg);
	return (comp);
}

// int main(int argc, char **argv){
	

// 	int i ;

// 	argc = i;
// 	ft_printf(NULL);
// 	return (0);
// }