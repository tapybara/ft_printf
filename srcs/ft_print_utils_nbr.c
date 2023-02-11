/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/12 00:19:53 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

bool	need_put_empry_char(t_print *tab, long long num)
{
	if (!num && tab->dot && !tab->prec)
	{
		ft_print_str(tab, "");
		return (true);
	}
	return (false);
}

void	ft_print_nbr(t_print *tab, int num)
{
	char	*nbr;
	long	lnum;
	int		len;

	if (need_put_empry_char(tab, (long long)num))
		return ;
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
		ft_print_nbr_util(tab, nbr, len);
	}
	free(nbr);
}

void	ft_print_uint(t_print *tab, unsigned int num)
{
	char	*nbr;
	int		len;

	if (need_put_empry_char(tab, (long long)num))
		return ;
	nbr = ft_uitoa(num);
	len = (int)ft_strlen(nbr);
	if (tab->width <= len && tab->prec <= len)
		ft_print_str(tab, nbr);
	else
	{
		ft_print_nbr_util(tab, nbr, len);
	}
	free(nbr);
}

void	ft_print_nbr_util(t_print *tab, char *nbr, int len)
{
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
