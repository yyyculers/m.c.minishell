/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:36:22 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/04 14:54:02 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_digit(int number)
{
	unsigned int	digit;

	digit = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		digit += 1;
	}
	while (number != 0)
	{
		number = number / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	number;

	len = ft_get_digit(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	if (n < 0)
	{
		number = -n;
		str[0] = '-';
	}
	else
		number = n;
	if (number == 0)
		str[0] = '0';
	str[len] = '\0';
	while (number != 0)
	{
		str[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

// int main()
// {
//     printf("%s\n", ft_itoa());
//     return (0);
// }
