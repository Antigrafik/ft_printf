/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:49:55 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/07 11:46:24 by mmurgia-         ###   ########.fr       */
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
	else if (type == 'x' || type == 'X')
		print_str += ft_print_hex(va_arg(args, unsigned int), type);
	else if (type == 'p')
		print_str += ft_print_str("0x") \
			+ ft_print_hex(va_arg(args, unsigned long int), type);
	else
		if (type == 'u')
			print_str += ft_print_unsigned_num(va_arg(args, unsigned int));
	return (print_str);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		print_str;
	int		i;

	i = 0;
	print_str = 0;
	va_start(args, str);
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

/* int	main(void)
{ */
/* 	char			c;
	char			*str;
	int				i;
	unsigned int	u;

	i = 0;
	c = 'M';
	str = "undo.";
	u = 429496729; */
/* 	ft_printf(" %x ", LONG_MAX);
	printf(" %lx ", LONG_MAX);
	return (0);
} */
