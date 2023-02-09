/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/09 22:18:25 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_print_nbr(t_print *tab, int num)
{
	char	*nbr;
	int		margin;

	nbr = ft_itoa(num);
	if (tab->width <= (int)ft_strlen(nbr))
		ft_print_str(tab, nbr);
	else
	{
		margin = tab->width - (int)ft_strlen(nbr);
		if (tab->dash)
		{
			ft_print_str(tab, nbr);
			fill_the_margin(tab, margin);
		}
		else
		{
			fill_the_margin(tab, margin);
			ft_print_str(tab, nbr);
		}
	}
	free(nbr);
}

void	ft_print_uint(t_print *tab, unsigned int num)
{
	char	*nbr;

	nbr = ft_uitoa(num);
	ft_print_str(tab, nbr);
	free(nbr);
}
