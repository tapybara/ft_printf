/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:33:29 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 15:33:20 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(char *str)
{
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}

void	ft_print_str(t_print *tab, char *str)
{
	int	len;

	if (!str)
	{
		tab->tl += ft_putstr("(null)");
		return ;
	}
	else if (is_empty_char_required(tab, true))
		return ;
	len = (int)ft_strlen(str);
	ft_print_str_with_flags(tab, str, len);
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
		tab->tl += ft_putchar(*str++);
	if (tab->dash)
		fill_the_margin(tab, len);
}
