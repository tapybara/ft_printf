/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 21:10:45 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_print_nbr(t_print *tab, int num)
{
	char	*nbr;

	nbr = ft_itoa(num);
	ft_print_str(tab, nbr);
	free(nbr);
}

void	ft_print_uint(t_print *tab, unsigned int num)
{
	char	*nbr;

	nbr = ft_uitoa(num);
	ft_print_str(tab, nbr);
	free(nbr);
}
