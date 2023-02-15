/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:49:26 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/15 19:03:43 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	eval_convspec(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(tab, va_arg(tab->args, int));
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
	else if (format[i] == '%')
		ft_print_str(tab, "%");
}

// Evaluation_Asterisk
static void	eval_asterisk(t_print *tab, const char *format, int i)
{
	char	*star_str;
	int		index;

	index = 0;
	if (format[i] == '*')
	{
		if (!tab->dot)
		{
			star_str = ft_itoa(va_arg(tab->args, int));
			while (star_str[index] != '\0')
				eval_flags(tab, star_str, index++);
			free(star_str);
		}
		else
		{
			tab->prec = va_arg(tab->args, int);
			if (tab->prec < 0)
			{
				tab->dot = 0;
				tab->prec = 0;
			}
		}
	}
}

// Evaluation_Field_Width_and_Precision
void	count_width_and_precision(t_print *tab, const char *format, int i)
{
	eval_asterisk(tab, format, i);
	if (!tab->dot)
	{
		if (ft_isdigit((int)format[i]))
		{
			tab->width *= 10;
			tab->width += (format[i] - '0');
		}
	}
	else
	{
		if (ft_isdigit((int)format[i]))
		{
			tab->prec *= 10;
			tab->prec += (format[i] - '0');
		}
	}
}

// Evaluation_Flag
void	eval_flags(t_print *tab, const char *format, int i)
{
	if (!tab->dot)
	{
		if (format[i] == '.')
			tab->dot = 1;
		else if (format[i] == '#')
			tab->prefix = 1;
		else if (format[i] == ' ')
			tab->space = 1;
		else if (format[i] == '+')
			tab->plus = 1;
		else if (format[i] == '-')
			tab->dash = 1;
		else if (format[i] == '0' && !tab->width)
			tab->zero = 1;
	}
	count_width_and_precision(tab, format, i);
}

// eval_start(main)
int	eval_start(t_print *tab, const char *format, int i)
{
	init_tab(tab);
	while (!ft_strchr(CONVERT_SPEC, format[i]) && format[i] != '\0')
	{
		eval_flags(tab, format, i);
		i++;
	}
	if (format[i] == '\0')
		return (-1);
	eval_convspec(tab, format, i);
	return (++i);
}
