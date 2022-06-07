/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:07:31 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/06/07 11:43:44 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>
# include <xlocale.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	ft_printf(char const *str, ...);
int	ft_format(va_list args, char type);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_num(int n);
int	ft_print_percentage(void);
int	ft_print_hex(unsigned long int num, char c);
int	ft_print_unsigned_num(unsigned int n);

#endif