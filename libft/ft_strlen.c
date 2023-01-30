/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:02:02 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 22:49:09 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*str;

	str = argv[1];
	if (argc > 2)
		return (0);
	else
	{
		printf("%lu\n", ft_strlen(str));
		printf("%lu\n", strlen(str));
	}
	return (1);
}
*/