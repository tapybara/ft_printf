/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:33:29 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/15 22:03:29 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar(t_print *tab, int c)
{
	if (tab->tl != INT_MAX)
		return (write(STDOUT_FILENO, &c, 1));
	tab->is_print_full = true;
	return (0);
}

int	ft_putstr(t_print *tab, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (len-- && !tab->is_print_full)
		i += ft_putchar(tab, *str++);
	return (i);
}

void	ft_print_str_with_flags(t_print *tab, char *str, int len)
{
	int	print_len;

	if (tab->prec < len && tab->dot)
		len = tab->prec;
	print_len = len;
	if (!tab->dash)
		fill_the_margin(tab, len);
	while (print_len--)
		tab->tl += ft_putchar(tab, *str++);
	if (tab->dash)
		fill_the_margin(tab, len);
}

void	ft_print_str(t_print *tab, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	ft_print_str_with_flags(tab, str, len);
}

void	ft_print_char(t_print *tab, int c)
{
	if (!tab->dash)
		fill_the_margin(tab, 1);
	tab->tl += ft_putchar(tab, c);
	if (tab->dash)
		fill_the_margin(tab, 1);
}
