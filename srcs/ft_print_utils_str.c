/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:33:29 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/07 21:33:34 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab, int c)
{
	tab->tl += write(STDOUT_FILENO, &c, 1);
}

void	ft_print_str(t_print *tab, char *str)
{
	if (!str)
		return ;
	tab->tl += write(STDOUT_FILENO, str, ft_strlen(str));
}
