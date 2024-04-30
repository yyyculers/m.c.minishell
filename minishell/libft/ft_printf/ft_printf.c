/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:18:03 by ychiba            #+#    #+#             */
/*   Updated: 2024/01/10 17:43:51 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_judge_fmt(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (*format == 'd' || *format == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		count += ft_print_uint(va_arg(args, unsigned int));
	else if (*format == 's')
		count += ft_printstring(va_arg(args, char *));
	else if (*format == 'p')
		count += ft_print_address(va_arg(args, void *));
	else if (*format == 'x')
		count += ft_print_lowerhexa(va_arg(args, unsigned int));
	else if (*format == 'X')
		count += ft_print_upperhexa(va_arg(args, unsigned int));
	else if (*format == '%')
		count += ft_putchar('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	const char		*format = fmt;
	int				count;
	int				tmp_count;

	count = 0;
	va_start(args, fmt);
	while (*format)
	{
		if (*format == '%')
		{
			tmp_count = ft_judge_fmt(format + 1, args);
			if (tmp_count == -1)
				return (write(1, "-1", 2));
			count += tmp_count;
			format++;
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
