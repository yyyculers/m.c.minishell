/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:13:30 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/16 14:24:27 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_change_hexa(uintptr_t	address)
{
	int			count;
	uintptr_t	rem;

	count = 0;
	if (address / 16 > 0)
		count += ft_change_hexa(address / 16);
	rem = address % 16;
	if (rem <= 9)
		ft_putchar('0' + rem);
	else
		ft_putchar('a' + rem - 10);
	return (count + 1);
}

int	ft_print_address(void *ptr)
{
	uintptr_t	address;
	int			count;

	count = 0;
	address = (uintptr_t)ptr;
	if (ptr == 0)
		return (write (1, "0x0", 3));
	count += write (1, "0x", 2);
	count += ft_change_hexa(address);
	return (count);
}
