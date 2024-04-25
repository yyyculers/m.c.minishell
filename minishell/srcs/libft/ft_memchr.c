/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:03:23 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 16:36:26 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	if (s == NULL)
		return (0);
	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	return (0);
}

// int	main()
// {
// 	char	*a;
// 	char	*b;

// 	a = ft_memchr("ascavhdfchtdf", '\0', 30);
// 	b = memchr("ascavhdfchtdf", '\0', 30);
// 	printf("%s\n", a);
// 	printf("%s\n", b);
// 	return (0);
// }
