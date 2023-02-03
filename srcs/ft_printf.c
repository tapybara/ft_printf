/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:17:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/03 22:37:02 by okuyamataka      ###   ########.fr       */
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
	int	i;
	int	ret;

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
			i = eval_start(tab, format, i + 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}

#include <stdio.h>

int main(void)
{
	int res;
	char	c = 'c';
	char	s[] = "strings";
	int	num = 42;
	unsigned int	unum = 123;

	res = ft_printf("abcde");	//Non args
	printf("\t:%d\n", res);
	res = ft_printf("%c", c);
	printf("\t:%d\n", res);
	res = ft_printf("%s", s);
	printf("\t:%d\n", res);
	res = ft_printf("%p", s);
	printf("\t:%d\n", res);
	res = ft_printf("%d", num);
	printf("\t:%d\n", res);
	res = ft_printf("%i", num);
	printf("\t:%d\n", res);
	res = ft_printf("%u", unum);
	printf("\t:%d\n", res);
	res = ft_printf("%x", 0xff);
	printf("\t:%d\n", res);
	res = ft_printf("%%");
	printf("\t:%d\n", res);
}
