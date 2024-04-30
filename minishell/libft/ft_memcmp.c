/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:33:52 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 16:35:44 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	dst = (char *)s1;
	src = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (dst[i] != src[i])
			return ((unsigned char)dst[i] - (unsigned char)src[i]);
		i++;
	}
	return (0);
}

// int	main()
// {
// 	int	a;
// 	int	b;
// 	int	c;
// 	int	d;

// 	a = ft_memcmp("abc", "ab", 0);
// 	b = memcmp("abc", "ab", 0);
// 	c = ft_memcmp("abc", "ab", 4);
// 	d = memcmp("abd", "ab", 4);
// 	printf("%d\n", a);
// 	printf("%d\n", b);
// 	printf("%d\n", c);
// 	printf("%d\n", d);
// 	return (0);
// }
