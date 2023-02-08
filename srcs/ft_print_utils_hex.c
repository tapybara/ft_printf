/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:34:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 23:33:45 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_print_ptr(t_print *tab, void *p)
{
	unsigned long long	ptr;

	ptr = (unsigned long long)p;
	ft_print_str(tab, "0x");
	ft_print_hex_ull(tab, ptr);
}

void	ft_print_hex_ull(t_print *tab, unsigned long long ptr)
{
	if (ptr >= HEXA_NUM)
	{
		ft_print_hex_ull(tab, ptr / HEXA_NUM);
		ft_print_hex_ull(tab, ptr % HEXA_NUM);
	}
	else if (ptr >= 10)
		ft_print_char(tab, ((int)ptr - 10) + 'a');
	else
		ft_print_char(tab, (int)ptr + '0');
}

void	ft_print_hex(t_print *tab, unsigned int num, int is_upper)
{
	if (num >= HEXA_NUM)
	{
		ft_print_hex(tab, num / HEXA_NUM, is_upper);
		ft_print_hex(tab, num % HEXA_NUM, is_upper);
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
