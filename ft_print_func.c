/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:50:40 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/07 11:39:47 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	caracter;

	caracter = 0;
	caracter += write(1, &c, 1);
	return (caracter);
}

int	ft_print_str(char *str)
{
	int	i;
	int	string;

	i = 0;
	string = 0;
	if (!str)
	{
		return (ft_print_str("(null)"));
	}
	while (str[i])
	{
		string += write(1, &str[i], 1);
		i++;
	}
	return (string);
}

int	ft_print_num(int n)
{
	int	number;

	number = 0;
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		number += write (1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		number += ft_print_num(n / 10);
	n = n % 10;
	if (n < 10)
		number += ft_print_char(n + 48);
	return (number);
}
