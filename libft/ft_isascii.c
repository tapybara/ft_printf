/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:20:00 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 20:09:28 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
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
		printf("%d\n", ft_isascii(num));
		printf("%d\n", isascii(num));
	}
	return (1);
}
*/