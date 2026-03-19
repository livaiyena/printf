/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:30:00 by kapaydin          #+#    #+#             */
/*   Updated: 2026/03/19 21:45:09 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	char	*tmp;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	tmp = s;
	while (*s++)
		write(1, s, 1);
	return (s - tmp);
}
