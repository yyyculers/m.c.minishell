/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upperhexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:53:06 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/13 22:53:06 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upperhexa(unsigned int nmb)
{
	int	count;
	int	rem;

	count = 0;
	rem = 0;
	if (nmb / 16 > 0)
		count += ft_print_upperhexa(nmb / 16);
	rem = nmb % 16;
	if (rem <= 9)
		ft_putchar('0' + rem);
	else
		ft_putchar('A' + rem - 10);
	return (count + 1);
}
