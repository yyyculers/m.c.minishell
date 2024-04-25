/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:19:57 by ychiba            #+#    #+#             */
/*   Updated: 2024/03/02 16:47:58 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char a)
{
	if ((9 <= a && a <= 13) || a == 32)
		return (1);
	return (0);
}

long int	ft_check_intlong(const char *nptr, int sign, size_t i)
{
	long int	result;

	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (((result * sign == LONG_MAX / 10)
				&& ((nptr[i] - '0') > LONG_MAX % 10))
			|| (result * sign > LONG_MAX / 10))
		{
			return (LONG_MAX);
		}
		if (((result * sign == LONG_MIN / 10)
				&& ((nptr[i] - '0') * sign <= LONG_MIN % 10))
			|| (result * sign < LONG_MIN / 10))
		{
			return (LONG_MIN);
		}
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_atoi(char *nptr)
{
	size_t	i;
	int		sign;
	int		num;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{	
			sign = -1;
			i++;
		}
	}
	num = (int)ft_check_intlong(nptr, sign, i);
	return (num);
}

// int	main()
// {
// 	char	*nptr = " a922337203685477580";
// 	int	i = atoi(nptr);
// 	int	k = ft_atoi(nptr);

// 	printf("%d\n", i);
// 	printf("%d\n", k);
// 	return (0);
// }
