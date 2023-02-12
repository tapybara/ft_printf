/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:03:54 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 23:06:53 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	fill_the_margin(t_print *tab, int len)
{
	char	margin_char;
	int		margin;

	margin = 0;
	if (tab->width > len)
		margin = tab->width - len;
	if (!tab->dash && tab->zero)
	{
		margin_char = '0';
		if (tab->is_negative)
			tab->tl += ft_putchar('-');
	}
	else
		margin_char = ' ';
	while (margin--)
		tab->tl += ft_putchar(margin_char);
	if (tab->is_negative && !tab->zero && !tab->dash)
		tab->tl += ft_putchar('-');
}

void	fill_the_margin_base(t_print *tab, int len)
{
	char	margin_char;
	int		margin;

	margin = 0;
	if (tab->width > len)
		margin = tab->width - len;
	margin_char = ' ';
	while (margin--)
		tab->tl += ft_putchar(margin_char);
}

bool	is_empty_char_required(t_print *tab, bool num_zero)
{
	if (num_zero && !tab->width && tab->dot && !tab->prec)
	{
		tab->tl += ft_putstr("");
		return (true);
	}
	return (false);
}
