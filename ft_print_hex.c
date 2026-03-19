/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:30:00 by kapaydin          #+#    #+#             */
/*   Updated: 2026/03/19 21:34:34 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	if (format == 'x')
		len += ft_print_char("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		len += ft_print_char("0123456789ABCDEF"[n % 16]);
	return (len);
}
