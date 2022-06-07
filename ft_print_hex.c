/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:50:40 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/07 11:43:41 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long int num, char c)
{
	int		hex;

	hex = 0;
	if (c == 'x' || c == 'p')
	{
		if (num >= 16)
			hex = ft_print_hex(num / 16, c);
		hex += ft_print_char("0123456789abcdef"[num % 16]);
	}
	else if (c == 'X')
	{
		if (num >= 16)
			hex += ft_print_hex(num / 16, c);
		hex += ft_print_char("0123456789ABCDEF"[num % 16]);
	}
	return (hex);
}
