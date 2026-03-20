/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:30:00 by kapaydin          #+#    #+#             */
/*   Updated: 2026/03/20 13:19:46 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		print_length += ft_print_nbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned long long), format);
	else if (format == '%')
		print_length += ft_print_char('%');
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		print_length;
	va_list	args;

	print_length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			print_length += ft_format(args, *++str);
		else
			print_length += ft_print_char(*str);
		if (*str)
			str++;
	}
	va_end(args);
	return (print_length);
}
