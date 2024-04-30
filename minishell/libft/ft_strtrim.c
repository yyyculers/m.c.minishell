/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:05:17 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/28 20:05:17 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;
	char	*str;

	str = 0;
	if (s1 != NULL && set != NULL)
	{
		start = 0;
		last = ft_strlen(s1);
		while (s1[start] != '\0' && ft_strchr(set, s1[start]) != 0)
			start++;
		while (ft_strchr(set, s1[last - 1]) != 0 && last > start)
			last--;
		str = (char *)malloc(sizeof(char) * (last - start + 1));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s1[start], last - start + 1);
	}
	return (str);
}

// int main()
// {
//     printf("%s\n", ft_strtrim("12421AAAA1241232", "1234"));
//     return (0);
// }