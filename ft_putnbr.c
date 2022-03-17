/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:53:58 by iouardi           #+#    #+#             */
/*   Updated: 2021/11/29 01:34:54 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int *i)
{
	int	nb;

	if (n == -2147483648)
	{
		*i = *i + ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		*i = *i + ft_putchar('-');
		n *= -1;
	}
	nb = n;
	if (n > 9)
		ft_putnbr(n / 10, i);
	*i = *i + ft_putchar((n % 10) + 48);
}

void	ft_putnbr_unsigned(unsigned int n, int *i)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10, i);
	ft_putchar(n % 10 + 48);
	*i = *i + 1;
}
