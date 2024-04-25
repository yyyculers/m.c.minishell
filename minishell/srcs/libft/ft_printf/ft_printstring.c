/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:52:40 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/18 15:38:30 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *s)
{
	int	count;
	int	tmp_count;

	count = 0;
	tmp_count = 0;
	if (s == NULL)
		return (write (1, "(null)", 6));
	tmp_count = ft_putstr(s);
	if (tmp_count == -1)
		return (-1);
	count += tmp_count;
	return (count);
}
