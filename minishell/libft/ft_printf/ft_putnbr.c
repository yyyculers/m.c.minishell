/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:22:45 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/16 15:10:01 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			count += ft_putstr("-2147483648");
			return (count);
		}
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (count + 1);
}
