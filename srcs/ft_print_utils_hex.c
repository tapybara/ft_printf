/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:34:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/07 23:42:13 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_print_hex(t_print *tab, unsigned int num, int is_upper)
{
	if (!num)
		return ;
	if (is_upper == 1)
		ft_print_str(tab, "0X");
	else if (is_upper == 0)
		ft_print_str(tab, "0x");
	ft_recursive_print_hex(tab, num, is_upper);
}

void	ft_recursive_print_hex(t_print *tab, unsigned int num, int is_upper)
{
	if (num >= 16)
	{
		ft_recursive_print_hex(tab, num / 16, is_upper);
		ft_recursive_print_hex(tab, num % 16, is_upper);
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
