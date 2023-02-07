/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:17:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/07 23:52:24 by okuyamataka      ###   ########.fr       */
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

/*For Debug under the below*/
#include <stdio.h>

// void	eval_convspec(t_print *tab, const char *format, int i)
// {
// 	if (format[i] == 'c')
// 		printf("c");
// 		// ft_putchar(va_args(tab, char));
// 	else if (format[i] == 's')
// 		printf("s");
// 		// ft_putstr(va_args(tab, char *));
// 	else if (format[i] == 'p')
// 		printf("p");
// 		// ft_putpointer(va_args(tab, unsigned long long));
// 	else if (format[i] == 'd' || format[i] == 'i')
// 		printf("d or i");
// 		// ft_putnbr(va_args(tab, int));
// 	else if (format[i] == 'u')
// 		printf("u");
// 		// ft_putunsignedint(va_args(tab, unsigned int));
// 	else if (format[i] == 'x' || format[i] == 'X')
// 		printf("x or X");
// 		// ft_puthex(va_args(tab, unsigned int));
// 	else if (format[i] == '%')
// 	{
// 		printf("%%");
// 		tab->tl += 1;
// 	}
// }

// // // Evaluation_Flag
// int	eval_flags(t_print *tab, const char *format, int i)
// {
// 	if (format[i] == '-')
// 	{
// 		tab->dash = 1;
// 		i++;
// 	}
// 	else if (format[i] == '0')
// 	{
// 		tab->zero = 1;
// 		i++;
// 	}
// 	else if (format[i] == '.')
// 	{
// 		tab->dot = 1;
// 		i++;
// 	}
// 	else if (format[i] == '*')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// // eval_start(main)
// int	eval_start(t_print *tab, const char *format, int i)
// {
// 	const char *CONVERT_SPEC;

// 	CONVERT_SPEC = "cspdiuxX%%";
// 	while (!ft_strchr(CONVERT_SPEC, format[i]))
// 	{
// 		i = eval_flags(tab, format, i);
// 		// Function(Field Width)
// 		// Function(Precision)
// 		// Function(length)

// 		// 上記4種類に掛からない文字列のパターン有り得る？
// 	}
// 	eval_convspec(tab, format, i);
// 	return (++i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	const char	*str;

// 	str = (char *)s;
// 	while (*str != '\0')
// 	{
// 		if (*str == (char)c)
// 			return ((char *)str);
// 		str++;
// 	}
// 	if (c == '\0')
// 		return ((char *)str);
// 	return (NULL);
// }

int main(void)
{
	int res;
	char	c = 'C';
	char	s[] = "strings";
	int	num1 = 42;
	int	num2 = 24;
	unsigned int	unum = 123;

	res = ft_printf("FT  %c, %s, %d, %i", c, s, num1, num2);
	printf("\t=>%d\n", res);
	res = printf("ORG %c, %s, %d, %i", c, s, num1, num2);
	printf("\t=>%d\n", res);
	res = ft_printf("FT  %x", 0xff);
	printf("\t=>%d\n", res);
	res = printf("ORG %x", 0xff);
	printf("\t=>%d\n", res);
	res = ft_printf("FT  %p", s);
	printf("\t=>%d\n", res);
	res = ft_printf("FT  %u", unum);
	printf("\t=>%d\n", res);
	res = ft_printf("FT  %%");
	printf("\t=>%d\n", res);
}
