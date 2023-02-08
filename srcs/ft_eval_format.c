/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:49:26 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/09 00:21:24 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

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

// Evaluation_Flag
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
	return (i);
}

// Evaluation_Field_Width
int	eval_field_width(t_print *tab, const char *format, int i)
{
	if (tab->dot)
		return (i);
	while (format[i] == '*' || ft_isdigit((int)format[i]))
		if (format[i] == '*' && !tab->dot)
		tab->width = va_arg(tab->args, int);
	else if (ft_isdigit((int)format[i]))
	{
		tab->width *= 10;
		tab->width += ft_atoi(format[i]);
	}
	return (i);
}

// eval_start(main)
int	eval_start(t_print *tab, const char *format, int i)
{
	while (!ft_strchr(CONVERT_SPEC, format[i]))
	{
		i = eval_flags(tab, format, i);
		// i = eval_field_width(tab, format, i);
		// Function(Field Width)
		// Function(Precision)
		// Function(length)
		// 上記4種類に掛からない文字列のパターン有り得る？
	}
	eval_convspec(tab, format, i);
	return (++i);
}
