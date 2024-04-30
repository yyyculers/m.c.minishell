/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:21:19 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/21 19:57:18 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s != 0)
	{
		s++;
		len++;
	}
	return (len);
}

// int	main()
// {
// 	size_t	i;

// 	i = ft_strlen("123456789");
// 	printf("%zu\n", i);
// 	return (0);
// }
