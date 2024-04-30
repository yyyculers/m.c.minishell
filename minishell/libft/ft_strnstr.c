/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:52:55 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/29 16:54:16 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (haystack == 0)
		return (NULL);
	if (n_len == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len >= n_len)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, n_len) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}

// int	main()
// {
// 	char	*a;
// 	char	*b;

// 	a = ft_strnstr("Lick alike soccer", "like", 17);
// 	b = strnstr("Lick alike soccer", "like", 17);
// 	printf("%s\n", a);
// 	printf("%s\n", b);
// 	return (0);
// }
