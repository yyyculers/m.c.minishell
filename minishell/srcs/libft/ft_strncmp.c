/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:19:07 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 16:42:32 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

// 	a = ft_strncmp("libft-test-tokyo", "l", 3);
// 	b = strncmp("libft-test-tokyo", "l", 4);
// 	c = ft_strncmp("abc", "ab", 4);
// 	d = strncmp("abc", "abcd", 4);
// 	printf("%d\n", a);
// 	printf("%d\n", b);
// 	printf("%d\n", c);
// 	printf("%d\n", d);
// 	return (0);
// }
