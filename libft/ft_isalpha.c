/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:45:14 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 20:04:18 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
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
		printf("%d\n", ft_isalpha(num));
		printf("%d\n", isalpha(num));
	}
	return (1);
}
*/