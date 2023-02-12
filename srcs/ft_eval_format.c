/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:49:26 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 18:13:15 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	eval_convspec(t_print *tab, const char *format, int i)
{
	if (format[i] == '%')
		tab->tl += ft_putchar('%');
	else if (format[i] == 'c')
		tab->tl += ft_putchar(va_arg(tab->args, int));
	else if (format[i] == 's')
		ft_print_str(tab, va_arg(tab->args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_nbr(tab, va_arg(tab->args, int));
	else if (format[i] == 'u')
		ft_print_uint(tab, va_arg(tab->args, unsigned int));
	else if (format[i] == 'x')
		ft_print_hex(tab, va_arg(tab->args, unsigned int));
	else if (format[i] == 'X')
	{
		tab->is_upper = true;
		ft_print_hex(tab, va_arg(tab->args, unsigned int));
	}
	else if (format[i] == 'p')
		ft_print_ptr(tab, va_arg(tab->args, void *));
}

// Evaluation_Flag
void	eval_flags(t_print *tab, const char *format, int i)
{
	if (format[i] == '-')
		tab->dash = 1;
	else if (format[i] == '0' && !tab->width && !tab->dot)
		tab->zero = 1;
}

// Evaluation_Field_Width
void	eval_width_and_precision(t_print *tab, const char *format, int i)
{
	if (format[i] == '.')
		tab->dot = 1;
	if (!tab->dot)
	{
		if (format[i] == '*')
			tab->width = va_arg(tab->args, int);
		else if (ft_isdigit((int)format[i]))
		{
			tab->width *= 10;
			tab->width += (format[i] - '0');
		}
	}
	else
	{
		if (format[i] == '*')
			tab->prec = va_arg(tab->args, int);
		else if (ft_isdigit((int)format[i]))
		{
			tab->prec *= 10;
			tab->prec += (format[i] - '0');
		}
	}
}

// eval_start(main)
int	eval_start(t_print *tab, const char *format, int i)
{
	init_tab(tab);
	while (!ft_strchr(CONVERT_SPEC, format[++i]))
	{
		eval_flags(tab, format, i);
		eval_width_and_precision(tab, format, i);
	}
	eval_convspec(tab, format, i);
	return (++i);
}
