/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:19:48 by iouardi           #+#    #+#             */
/*   Updated: 2021/11/29 01:35:23 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_hex(unsigned int n, char x, int *i)
{
	char			*hex;

	hex = NULL;
	if (x == 'x')
		hex = "0123456789abcdef";
	else if (x == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_put_hex(n / 16, x, i);
	ft_putchar(hex[n % 16]);
	*i = *i + 1;
}

void	ft_put_p_hex(unsigned long n, int *i)
{
	char			*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_put_p_hex(n / 16, i);
	ft_putchar(hex[n % 16]);
	*i = *i + 1;
}
