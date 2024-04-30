/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:37:23 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 15:56:43 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*answer;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	answer = malloc(nmemb * size);
	if (answer == NULL)
		return (NULL);
	ft_bzero(answer, nmemb * size);
	return (answer);
}

// int	main()
// {
// 	printf("%s\n", ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	printf("%s\n", calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	return (0);
// }
