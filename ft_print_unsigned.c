/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:50:40 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/07 11:39:44 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_num(unsigned int n)
{
	int	dest;

	dest = 0;
	if (n >= 10)
		dest += ft_print_unsigned_num(n / 10);
	n = n % 10;
	if (n < 10)
		dest += ft_print_char(n + '0');
	return (dest);
}
