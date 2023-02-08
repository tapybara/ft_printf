/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:59:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 21:49:25 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		dot;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
}	t_print;

int	eval_start(t_print *tab, const char *format, int i);
int	eval_flags(t_print *tab, const char *format, int i);
void	eval_convspec(t_print *tab, const char *format, int i);

void	ft_print_char(t_print *tab, int c);
void	ft_print_str(t_print *tab, char *str);
void	ft_print_nbr(t_print *tab, int num);
void	ft_print_uint(t_print *tab, unsigned int num);
void	ft_print_ptr(t_print *tab, void *p);
void	ft_print_hex_ull(t_print *tab, unsigned long long num);
void	ft_print_hex(t_print *tab, unsigned int num, int is_upper);

#endif