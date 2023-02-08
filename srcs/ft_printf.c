/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:17:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 23:52:21 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static t_print	*init_tab(t_print *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->star = 0;
	tab->dot = 0;
	tab->width = 0;
	tab->tl = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

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
// #include <stdio.h>

// int main(void)
// {
// 	int res;
// 	char	c = 'C';
// 	char	s1[] = "strings";
// 	char	*s2 = NULL;
// 	int	num1 = 32;
// 	int	num2 = -32;
// 	unsigned int	unum = 123456789;

// 	printf("-------------------------------------------\n");
// 	res = printf("ORG :%c,%s,%d,%i:", c, s1, num1, num2);
// 	printf("\t=>%d\n", res);
// 	res = ft_printf("FT  :%c,%s,%d,%i:", c, s1, num1, num2);
// 	printf("\t=>%d\n", res);
// 	printf("-------------------------------------------\n");
// 	res = printf("ORG :%s", s2);
// 	printf("\t=>%d\n", res);
// 	res = ft_printf("FT  :%s", s2);
// 	printf("\t=>%d\n", res);
// 	printf("-------------------------------------------\n");
// 	res = printf("ORG :%x:%X:%x:%X:", num1, num1, num2, num2);
// 	printf("\t=>%d\n", res);
// 	res = ft_printf("FT  :%x:%X:%x:%X:", num1, num1, num2, num2);
// 	printf("\t=>%d\n", res);
// 	printf("-------------------------------------------\n");
// 	res = printf("ORG :%u:", unum);
// 	printf("\t=>%d\n", res);
// 	res = ft_printf("FT  :%u:", unum);
// 	printf("\t=>%d\n", res);
// 	printf("-------------------------------------------\n");
// 	res = printf("ORG :%p:%p:", s1, NULL);
// 	printf("\t=>%d\n", res);
// 	res = ft_printf("FT  :%p:%p:", s1, NULL);
// 	printf("\t=>%d\n", res);
// 	printf("-------------------------------------------\n");
// 	res = printf("ORG :%%:");
// 	printf("\t=>%d\n", res);
// 	res = ft_printf("FT  :%%:");
// 	printf("\t=>%d\n", res);
// 	printf("-------------------------------------------\n");
// }