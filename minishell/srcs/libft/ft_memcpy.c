/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:03:04 by ychiba            #+#    #+#             */
/*   Updated: 2023/12/18 14:17:41 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst1 = (char *)dst;
	src1 = (const char *)src;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str[6];
// 	char	str1[6];

// 	ft_memcpy(((void *)0), ((void *)0), 3);
// 	str[4] = '\0';
// 	printf("%s\n", str);
// 	memcpy(str1, "abcdefghi", 4);
// 	str1[4] = '\0';
// 	printf("%s\n", str1);
// 	return (0);
// }
