/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maialen <maialen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:50:40 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/05/31 13:18:01 by maialen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long int num, char c)
{
	int		hex;
	char	*str_minus;
	char	*str_mayus;

	hex = 0;
	str_minus = "0123456789abcdef";
	str_mayus = "0123456789ABCDEF";
	if (c == 'x' || c == 'p')
	{
		if (num >= 16)
			hex += ft_print_hex(num / 16, c);
		hex += ft_print_char(str_minus[num % 16]);
	}
	else if (c == 'X')
	{
		if (num >= 16)
			hex += ft_print_hex(num / 16, c);
		hex += ft_print_char(str_mayus[num % 16]);
	}
	return (hex);
}
