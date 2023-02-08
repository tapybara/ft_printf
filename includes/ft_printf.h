/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:59:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 23:33:14 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define CONVERT_SPEC "cspdiuxX%%"
# define HEXA_NUM 16

typedef struct s_print
{
	va_list	args;
	int		dash;
	int		zero;
	int		star;
	int		dot;
	int		width;
	int		tl;
}	t_print;

int		eval_start(t_print *tab, const char *format, int i);
int		eval_flags(t_print *tab, const char *format, int i);
void	eval_convspec(t_print *tab, const char *format, int i);

void	ft_print_char(t_print *tab, int c);
void	ft_print_str(t_print *tab, char *str);
void	ft_print_nbr(t_print *tab, int num);
void	ft_print_uint(t_print *tab, unsigned int num);
void	ft_print_ptr(t_print *tab, void *p);
void	ft_print_hex_ull(t_print *tab, unsigned long long num);
void	ft_print_hex(t_print *tab, unsigned int num, int is_upper);

#endif