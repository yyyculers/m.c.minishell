/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:19:53 by ychiba            #+#    #+#             */
/*   Updated: 2023/05/21 15:32:09 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main()
// {
// 	int	i;
// 	int	k;

// 	i = ft_isalpha(122);
// 	k = ft_isalpha(49);
// 	printf("%d\n", i);
// 	printf("%d\n", k);
// 	return (0);
// }
