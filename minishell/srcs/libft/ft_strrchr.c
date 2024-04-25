/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:37:08 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/29 15:26:56 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = ft_strlen(s1);
	if (c == 0)
		return (&s1[i]);
	while (i >= 0)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i--;
	}
	return (0);
}

// int	main()
// {
// 	char	*str;

// 	str = ft_strrchr("AABadcyadgcyd", 'd' - 256);
// 	printf("%s\n", str);
// 	printf("%s\n", strrchr("AABadcyadgcyd", 'd' - 256));
// 	return (0);
// }
