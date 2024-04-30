/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:29:04 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 16:58:36 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}

// int	main()
// {
// 	printf("%s(no.1)\n", ft_substr(" ", 10, 3));
// 	printf("%s(no.2)\n", ft_substr("-toky", 10, 3));
// 	printf("%s(no.3)\n", ft_substr("", 10, 0));
// 	printf("%s(no.4)\n", ft_substr("abcde", 2, 100));
// }
