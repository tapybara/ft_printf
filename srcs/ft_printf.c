/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:17:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/30 23:41:26 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static t_print	*init_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	size_t	i;
	ssize_t	ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	init_tab(tab);
	i = 0;
	ret = 0;
	va_start(tab->args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ret += write(1, &format[i++], sizeof(char));
		else
			return (0);
			// i = eval_format(tab, format, i + 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return ((int)ret);
}

#include <stdio.h>

int main(void)
{
	printf("abcde\n");	//Non args
	ft_printf("abcde");	//Non args
	// printf("%d", 12345);
	// ft_printf("%d", 12345);
	// printf("%c", '0');
	// ft_printf("%c", '0');
	// printf("%s", "string");
	// ft_printf("%s", "string");
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