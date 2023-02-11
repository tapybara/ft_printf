/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:17:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 03:20:39 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	init_tab(t_print *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->star = 0;
	tab->dot = 0;
	tab->width = 0;
	tab->prec = 0;
	tab->is_negative = 0;
	tab->prefix = 0;
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
			i = eval_start(tab, format, i);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}
