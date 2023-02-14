/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:03:54 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/14 19:53:09 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_put_sign(t_print *tab)
{
	if (tab->is_negative)
		tab->tl += ft_putchar('-');
	if (tab->plus)
		tab->tl += ft_putchar('+');
	if (tab->space)
		tab->tl += ft_putchar(' ');
}

void	fill_the_margin(t_print *tab, int len)
{
	char	margin_char;
	int		margin;

	margin = 0;
	if (tab->is_negative || tab->plus || tab->space)
		len++;
	if (tab->width > len)
		margin = tab->width - len;
	if (!tab->dash && tab->zero && !tab->dot)
	{
		margin_char = '0';
		ft_put_sign(tab);
	}
	else
		margin_char = ' ';
	while (margin--)
		tab->tl += ft_putchar(margin_char);
	if ((!tab->zero || tab->dot) && !tab->dash)
		ft_put_sign(tab);
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
	if (num_zero && tab->dot && !tab->prec)
		return (true);
	return (false);
}
