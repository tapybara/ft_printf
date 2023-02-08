/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:49:26 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 21:39:41 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

# include <stdio.h>

void	eval_convspec(t_print *tab, const char *format, int i)
{
	if (format[i] == '%')
		ft_print_char(tab, '%');
	else if (format[i] == 'c')
		ft_print_char(tab, va_arg(tab->args, int));
	else if (format[i] == 's')
		ft_print_str(tab, va_arg(tab->args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_nbr(tab, va_arg(tab->args, int));
	else if (format[i] == 'u')
		ft_print_uint(tab, va_arg(tab->args, unsigned int));
	else if (format[i] == 'x')
		ft_print_hex(tab, va_arg(tab->args, unsigned int), 0);
	else if (format[i] == 'X')
		ft_print_hex(tab, va_arg(tab->args, unsigned int), 1);
	else if (format[i] == 'p')
		ft_print_ptr(tab, va_arg(tab->args, void *));
}

// // Evaluation_Flag
int	eval_flags(t_print *tab, const char *format, int i)
{
	if (format[i] == '-')
	{
		tab->dash = 1;
		i++;
	}
	else if (format[i] == '0')
	{
		tab->zero = 1;
		i++;
	}
	else if (format[i] == '.')
	{
		tab->dot = 1;
		i++;
	}
	else if (format[i] == '*')
	{
		i++;
	}
	return (i);
}

// eval_start(main)
int	eval_start(t_print *tab, const char *format, int i)
{
	const char *CONVERT_SPEC;

	CONVERT_SPEC = "cspdiuxX%%";
	while (!ft_strchr(CONVERT_SPEC, format[i]))
	{
		i = eval_flags(tab, format, i);
		// Function(Field Width)
		// Function(Precision)
		// Function(length)

		// 上記4種類に掛からない文字列のパターン有り得る？
	}
	eval_convspec(tab, format, i);
	return (++i);
}


/*
%[Flag][Min Field Width].[Precision][length][Format]

*Mandatory*
	Format(変換子)	 -> [ cspdiuxX% ]
	Flags			-> [ -0.* ]

*Bonus*
	`n`, `f`, `g`, `e`
	`l`, `ll`, `h`, `hh`
	`#`, ` `, `+`
*/