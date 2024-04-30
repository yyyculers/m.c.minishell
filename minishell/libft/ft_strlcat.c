/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:33:05 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/27 16:34:17 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (size == 0)
		return (slen + size);
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main()
// {
// 	printf("%s\n", "part1");
// 	printf("%lu\n", ft_strlcat("eeeeee", "abc", 4));
// 	printf("%s\n", "part2");
// 	printf("%lu\n", strlcat("eeeeeee", "abc", 4));
// 	return (0);
// }
