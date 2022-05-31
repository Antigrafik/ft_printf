/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maialen <maialen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:07:31 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/05/31 13:18:16 by maialen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_printf(char const *str, ...);
int		ft_format(va_list args, char type);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_num(int n);
int		ft_print_percentage(void);
int		ft_print_hex(unsigned long long int num, char c);
int		ft_print_unsigned_num(unsigned int n);

#endif