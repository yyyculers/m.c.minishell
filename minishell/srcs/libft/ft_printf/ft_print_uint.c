/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:52:25 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/16 15:28:00 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int u)
{
	int			count;

	count = 0;
	if (u >= 10)
		count += ft_print_uint(u / 10);
	ft_putchar(u % 10 + '0');
	return (count + 1);
}
