/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:49:26 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/03 22:41:19 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

# include <stdio.h>

void	eval_convspec(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		printf("c");
		// ft_putchar(va_args(tab, char));
	else if (format[i] == 's')
		printf("s");
		// ft_putstr(va_args(tab, char *));
	else if (format[i] == 'p')
		printf("p");
		// ft_putpointer(va_args(tab, unsigned long long));
	else if (format[i] == 'd' || format[i] == 'i')
		printf("d or i");
		// ft_putnbr(va_args(tab, int));
	else if (format[i] == 'u')
		printf("u");
		// ft_putunsignedint(va_args(tab, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		printf("x or X");
		// ft_puthex(va_args(tab, unsigned int));
	else if (format[i] == '%')
	{
		printf("%%");
		tab->tl += 1;
	}
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

	CONVERT_SPEC = "cspdiuxX";
	while (!ft_strchr(CONVERT_SPEC, format[i]))
	{
		i = eval_flags(tab, format, i);
		// Function(Field Width)
		// Function(Precision)
		// Function(length)

		// 上記4種類に掛からない文字列のパターン有り得る？
	}
	eval_convspec(tab, format, i);
	return (i++);
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