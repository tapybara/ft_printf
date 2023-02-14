/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/15 00:25:52 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	count_base_digits(unsigned long long num, unsigned long long base)
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

void	ft_print_nbr_with_flags(t_print *tab, char *nbr, int len)
{
	if (tab->prec >= len)
	{
		tab->prec -= len;
		tab->width -= tab->prec;
	}
	else
		tab->prec = 0;
	if (!tab->dash)
		fill_the_margin(tab, len);
	else if (tab->is_negative)
		tab->tl += ft_putchar('-');
	else if (tab->plus)
		tab->tl += ft_putchar('+');
	else if (tab->space)
		tab->tl += ft_putchar(' ');
	while (tab->prec--)
		tab->tl += ft_putchar('0');
	if (tab->is_empty_char)
		tab->tl += ft_putstr("");
	else
		tab->tl += ft_putstr(nbr);
	if (tab->dash)
		fill_the_margin(tab, len);
}

void	ft_print_nbr(t_print *tab, int num)
{
	char	*nbr;
	int		len;
	long	lnum;

	lnum = (long)num;
	if (num < 0)
	{
		tab->is_negative = 1;
		lnum *= -1;
	}
	nbr = ft_ltoa(lnum);
	len = (int)ft_strlen(nbr);
	if (is_empty_char_required(tab, !num))
	{
		tab->is_empty_char = true;
		len = 0;
	}
	ft_print_nbr_with_flags(tab, nbr, len);
	free(nbr);
}

void	ft_print_uint(t_print *tab, unsigned int num)
{
	char	*nbr;
	int		len;

	nbr = ft_uitoa(num);
	len = (int)ft_strlen(nbr);
	if (is_empty_char_required(tab, !num))
	{
		tab->is_empty_char = true;
		len = 0;
	}
	ft_print_nbr_with_flags(tab, nbr, len);
	free(nbr);
}
