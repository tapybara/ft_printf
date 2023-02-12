/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:34:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 14:33:30 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static void	ft_print_hex_of_prefix(t_print *tab)
{
	if (tab->prefix)
	{
		if (tab->is_upper)
			tab->tl += ft_putstr("0x");
		else
			tab->tl += ft_putstr("0X");
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
			tab->tl += ft_putchar(((int)num - 10) + 'A');
		else
			tab->tl += ft_putchar(((int)num - 10) + 'a');
	}
	else
		tab->tl += ft_putchar((int)num + '0');
}

void	ft_print_base_with_flags(t_print *tab, unsigned long long num)
{
	int	len;

	len = count_base_digits(num, HEXA_BASE);
	if (tab->prefix)
		len += 2;
	if (tab->prec >= len)
	{
		tab->prec -= len;
		tab->width -= tab->prec;
	}
	if (!tab->dash)
		fill_the_margin(tab, len);
	else if (tab->is_negative)
		tab->tl += ft_putchar('-');
	while (tab->prec--)
		tab->tl += ft_putchar('0');
	ft_print_hex_of_prefix(tab);
	ft_print_ul_to_hex(tab, num);
	if (tab->dash)
		fill_the_margin(tab, len);
}

void	ft_print_ptr(t_print *tab, void *p)
{
	unsigned long long	ullnum;

	tab->prefix = 1;
	ullnum = (unsigned long long)p;
	ft_print_base_with_flags(tab, ullnum);
}

void	ft_print_hex(t_print *tab, unsigned int num)
{
	unsigned long long	ullnum;

	if (is_empty_char_required(tab, !num))
		return ;
	ullnum = (unsigned long long)num;
	ft_print_base_with_flags(tab, ullnum);
}
