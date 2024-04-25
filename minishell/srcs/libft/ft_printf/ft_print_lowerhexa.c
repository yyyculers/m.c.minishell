/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowerhexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:11:29 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/13 16:11:29 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lowerhexa(unsigned int nmb)
{
	int	count;
	int	rem;

	count = 0;
	rem = 0;
	if (nmb / 16 > 0)
		count += ft_print_lowerhexa(nmb / 16);
	rem = nmb % 16;
	if (rem <= 9)
		ft_putchar('0' + rem);
	else
		ft_putchar('a' + rem - 10);
	return (count + 1);
}
