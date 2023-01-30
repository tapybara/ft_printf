/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:40:08 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 20:11:19 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
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
		printf("%d\n", ft_isalnum(num));
		printf("%d\n", isalnum(num));
	}
	return (1);
}
*/