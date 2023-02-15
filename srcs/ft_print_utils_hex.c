/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:34:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/15 22:01:53 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_print_hex_of_prefix(t_print *tab)
{
	if (tab->prefix)
	{
		if (tab->is_upper)
			tab->tl += ft_putstr(tab, "0X");
		else
			tab->tl += ft_putstr(tab, "0x");
	}
}

void	ft_print_ul_to_hex(t_print *tab, unsigned long long num)
{
	if (num >= HEXA_BASE)
	{
		tab->prefix = 0;
		ft_print_ul_to_hex(tab, num / HEXA_BASE);
		ft_print_ul_to_hex(tab, num % HEXA_BASE);
	}
	else if (num >= 10)
	{
		if (tab->is_upper)
			tab->tl += ft_putchar(tab, ((int)num - 10) + 'A');
		else
			tab->tl += ft_putchar(tab, ((int)num - 10) + 'a');
	}
	else
		tab->tl += ft_putchar(tab, (int)num + '0');
}

void	ft_print_base_with_flags(t_print *tab, unsigned long long num, int len)
{
	if (tab->prec >= len)
	{
		tab->prec -= len;
		tab->width -= tab->prec;
	}
	else
		tab->prec = 0;
	if (tab->prefix)
		len += 2;
	if (!tab->dash)
		fill_the_margin(tab, len);
	else if (tab->is_negative)
		tab->tl += ft_putchar(tab, '-');
	ft_print_hex_of_prefix(tab);
	if (tab->is_empty_char)
		tab->tl += ft_putstr(tab, "");
	else
	{
		while (tab->prec--)
			tab->tl += ft_putchar(tab, '0');
		ft_print_ul_to_hex(tab, num);
	}
	if (tab->dash)
		fill_the_margin(tab, len);
}

void	ft_print_ptr(t_print *tab, void *p)
{
	unsigned long long	ullnum;
	int					len;

	tab->prefix = 1;
	ullnum = (unsigned long long)p;
	len = count_base_digits(ullnum, HEXA_BASE);
	if (is_empty_char_required(tab, !ullnum))
	{
		tab->is_empty_char = true;
		len = 0;
	}
	ft_print_base_with_flags(tab, ullnum, len);
}

void	ft_print_hex(t_print *tab, unsigned int num)
{
	unsigned long long	ullnum;
	int					len;

	len = count_base_digits(num, HEXA_BASE);
	if (is_empty_char_required(tab, !num))
	{
		tab->is_empty_char = true;
		len = 0;
	}
	ullnum = (unsigned long long)num;
	ft_print_base_with_flags(tab, ullnum, len);
}
