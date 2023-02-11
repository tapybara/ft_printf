/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/11 22:43:22 by okuyamataka      ###   ########.fr       */
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
	if (tab->width <= len && tab->prec <= len)
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
		if (tab->prec > (int)ft_strlen(nbr))
		{
			tab->prec -= (int)ft_strlen(nbr);
			tab->width -= tab->prec;
		}
		if (!tab->dash)
			fill_the_margin(tab, len);
		else if (tab->is_negative)
			ft_print_char(tab, '-');
		while (tab->prec--)
			ft_print_char(tab, '0');
		ft_print_str(tab, nbr);
		if (tab->dash)
			fill_the_margin(tab, len);
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
