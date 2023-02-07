/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:42 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/07 23:11:07 by okuyamataka      ###   ########.fr       */
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

// void	ft_print_ptr(t_print *tab, void *p)
// {
// 	unsigned long	*ptr;

// 	if (!p)
// 		return ;
// 	ptr = (unsigned long)p;
// 	ft_print_str(tab, "0x");
	
// }
