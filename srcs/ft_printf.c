/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:17:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/15 20:44:44 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	init_tab(t_print *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->star = 0;
	tab->dot = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->prefix = 0;
	tab->width = 0;
	tab->prec = 0;
	tab->is_negative = 0;
	tab->is_upper = false;
	tab->is_empty_char = false;
	tab->is_warning = false;
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab->tl = 0;
	i = 0;
	ret = 0;
	va_start(tab->args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ret += write(1, &format[i++], sizeof(char));
		else
			i = eval_start(tab, format, i + 1);
	}
	va_end(tab->args);
	if (tab->is_warning)
		ret = -1;
	else
		ret += tab->tl;
	free (tab);
	return (ret);
}
