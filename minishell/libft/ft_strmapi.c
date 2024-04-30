/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:49:52 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/01 17:49:52 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f (i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char to_uppercase(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32; // 小文字を大文字に変換
    }
    return c; // その他の文字は変換しない
}


int main()
{
    char *original = "Hello, World!";
    char *result = ft_strmapi(original, to_uppercase);
    printf("Original: %s\n", original);
    printf("Result: %s\n", result);
    free(result); 
    return 0;
}
*/