/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:04:30 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 16:27:24 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	if (s == NULL)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	str[7] = "adagvs";
// 	char	str2[7] = "adagvs";

// 	ft_memset(str, 99, 5);
// 	printf("%s\n", str);
// 	memset(str2, 99, 5);
// 	printf("%s\n", str2);
// 	return (0);
// }
