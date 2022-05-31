/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maialen <maialen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:49:55 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/05/31 13:18:37 by maialen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char type)
{
	int	print_str;

	print_str = 0;
	if (type == 'c')
		print_str += ft_print_char(va_arg(args, int));
	else if (type == 'd' || type == 'i')
		print_str += ft_print_num(va_arg(args, int));
	else if (type == 's')
		print_str += ft_print_str(va_arg(args, char *));
	else if (type == '%')
		print_str += ft_print_char('%');
	else if (type == 'u')
		print_str += ft_print_unsigned_num(va_arg(args, unsigned int));
	else if (type == 'x')
		print_str += ft_print_hex(va_arg(args, unsigned long long int), type);
	else if (type == 'X')
		print_str += ft_print_hex(va_arg(args, unsigned long long int), type);
	else if (type == 'p')
		print_str += ft_print_str("0x")
			+ ft_print_hex(va_arg(args, unsigned long long int), type);
	return (print_str);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		print_str;
	int		i;

	va_start(args, str);
	i = 0;
	print_str = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_str += ft_format(args, str[i + 1]);
			i += 2;
		}
		else
		{
			print_str += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (print_str);
}
