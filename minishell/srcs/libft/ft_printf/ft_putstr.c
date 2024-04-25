/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:25:30 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/16 21:55:25 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		count;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	i = ft_strlen(s);
	if (LONG_MAX < i)
		return (-1);
	count = write (1, s, ft_strlen(s));
	return (count);
}
