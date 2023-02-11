/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/11 21:26:46 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_print_nbr(t_print *tab, int num)
{
	char			*nbr;
	long			lnum;
	int				len;

	if (!num && tab->dot && !tab->prec)
	{
		ft_print_str(tab, "");
		return ;
	}
	nbr = ft_itoa(num);
	len = (int)ft_strlen(nbr);
	if (tab->width <= len)
		ft_print_str(tab, nbr);
	else
	{
		free(nbr);
		lnum = (long)num;
		if (num < 0)
		{
			tab->is_negative = 1;
			lnum *= -1;
		}
		nbr = ft_ltoa(lnum);
		if (!tab->dash)
			fill_the_margin(tab, len);
		else if (tab->is_negative)
			ft_print_char(tab, '-');
		ft_print_str(tab, nbr);
		if (tab->dash)
			fill_the_margin(tab, len);
	}
	

	// if (tab->width > len || tab->prec > len)
	// {
	// 	if (!tab->dash || tab->prec > len)
	// 	{
	// 		fill_the_margin(tab, len);
	// 		ft_print_str(tab, nbr);
	// 	}
	// 	else
	// 	{
	// 		ft_print_str(tab, nbr);
	// 		fill_the_margin(tab, len);
	// 	}
	// }
	// else
	free(nbr);
}

void	ft_print_uint(t_print *tab, unsigned int num)
{
	char	*nbr;

	nbr = ft_uitoa(num);
	ft_print_str(tab, nbr);
	free(nbr);
}
