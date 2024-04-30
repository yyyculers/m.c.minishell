/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:41:47 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/30 13:41:47 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*make_string(char const *s, char c)
{
	char const	*start;
	char		*string;
	int			len;

	start = s;
	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	ft_strlcpy(string, start, len + 1);
	return (string);
}

static void	check_malloc(char **ptr, int string_len)
{
	int	i;

	i = 0;
	while (i < string_len)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	split_string(char const *s, char c, char **result)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = make_string(s, c);
			if (!result[i])
			{
				check_malloc(result, i);
				return ;
			}
			i++;
			while (*s && *s != c)
				s++;
			s--;
		}
		s++;
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		exit (0);
	size = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		exit (0);
	split_string(s, c, result);
	return (result);
}
