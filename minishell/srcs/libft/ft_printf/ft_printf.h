/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychiba <ychiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:12:09 by ychiba            #+#    #+#             */
/*   Updated: 2023/06/14 13:20:13 by ychiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>

int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_put_uint(int n);
int		ft_print_int(int d);
int		ft_print_uint(unsigned int u);
int		ft_printchar(int c);
int		ft_printstring(char *s);
int		ft_print_address(void *ptr);
int		ft_print_lowerhexa(unsigned int nmb);
int		ft_print_upperhexa(unsigned int nmb);
int		ft_printf(const char *fmt, ...);
size_t	ft_strlen(const char *s);

#endif
