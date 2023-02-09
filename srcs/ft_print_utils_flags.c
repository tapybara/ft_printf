/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:03:54 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/09 22:10:42 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_the_margin(t_print *tab, int margin)
{
	while (margin--)
	{
		if (tab->zero)
			ft_print_char(tab, '0');
		else
			ft_print_char(tab, ' ');
	}
}
