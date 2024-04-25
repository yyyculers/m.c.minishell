/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:50:09 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/29 16:12:32 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

// int	main()
// {
// 	char	*a;
// 	char	*b;

// 	a = ft_strchr("ascavhdfchtdf", '\0');
// 	b = strchr("ascavhdfchtdf", '\0');
// 	printf("%s\n", a);
// 	printf("%s\n", b);
// 	return (0);
// }
