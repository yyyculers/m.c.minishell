/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:59:27 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/02 11:59:27 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else if (n < 0)
	{
		if (n == INT_MIN)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
	}
}

// int main()
// {
//     ft_putnbr_fd(-123, 1);
//     return (0);
// }