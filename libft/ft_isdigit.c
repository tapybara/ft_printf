/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:32:24 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 20:06:29 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
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
		printf("%d\n", ft_isdigit(num));
		printf("%d\n", isdigit(num));
	}
	return (1);
}
*/