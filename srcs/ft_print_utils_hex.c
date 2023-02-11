/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:34:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 03:21:03 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static int	count_base_digits(unsigned long long num, unsigned long long base)
{
	int	count;

	count = 1;
	while (num >= (unsigned long long)base)
	{
		num /= base;
		count++;
	}
	return (count);
}

void	ft_print_ptr(t_print *tab, void *p)
{
	int	len;
	unsigned long long	num;

	tab->prefix = 1;
	num = (unsigned long long)p;
	len = count_base_digits((unsigned long long)num, HEXA_BASE);
	len += 2;
	if (tab->width <= len && tab->prec <= len)
		ft_print_base_with_flags(tab, num, len, 0);
	else
		ft_print_base_with_flags(tab, num, len, 0);
}

void	ft_print_ptr_to_hex(t_print *tab, unsigned long long num)
{
	if (num >= HEXA_BASE)
	{
		ft_print_ptr_to_hex(tab, num / HEXA_BASE);
		ft_print_ptr_to_hex(tab, num % HEXA_BASE);
	}
	else if (num >= 10)
		ft_print_char(tab, ((int)num - 10) + 'a');
	else
		ft_print_char(tab, (int)num + '0');
}

void	ft_print_hex(t_print *tab, unsigned int num, int is_upper)
{
	int	len;

	if (is_empty_char_required(tab, !num))
		return ;
	len = count_base_digits((unsigned long long)num, HEXA_BASE);
	if (tab->width <= len && tab->prec <= len)
		ft_print_ul_to_hex(tab, (unsigned long long)num, is_upper);
	else
		ft_print_base_with_flags(tab, (unsigned long long)num, len, is_upper);
}

void	ft_print_ul_to_hex(t_print *tab, unsigned long long num, int is_upper)
{
	if (tab->prefix)
		ft_print_str(tab, "0x");
	if (num >= HEXA_BASE)
	{
		tab->prefix = 0;
		ft_print_ul_to_hex(tab, num / HEXA_BASE, is_upper);
		ft_print_ul_to_hex(tab, num % HEXA_BASE, is_upper);
	}
	else if (num >= 10)
	{
		if (is_upper)
			ft_print_char(tab, ((int)num - 10) + 'A');
		else
			ft_print_char(tab, ((int)num - 10) + 'a');
	}
	else
		ft_print_char(tab, (int)num + '0');
}
