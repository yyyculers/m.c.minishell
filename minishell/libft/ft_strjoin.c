/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:39:11 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/05 17:10:53 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	dst = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (dst == 0)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		dst[i] = s1[i];
		i++;
	}
	while (j < ft_strlen((char *)s2))
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
