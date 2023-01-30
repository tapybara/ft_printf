/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:42:14 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 20:15:50 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	num;

	num = (int)(*argv[1]);
	if (argc > 2)
		return (0);
	else
	{
		printf("%d\n", ft_isprint(num));
		printf("%d\n", isprint(num));
	}
	return (1);
}
*/