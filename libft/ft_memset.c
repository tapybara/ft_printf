/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:43:45 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 22:48:48 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*p++ = c;
	return (b);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	buf[atoi(argv[1])];
	char	s;
	size_t	size;

	s = *argv[2];
	size = (size_t)(atoi(argv[3]));
	if (argc > 4)
		return (0);
	else
	{
		printf("STR     = %s\n", buf);
		ft_memset(buf, s, size);
		printf("AFT_STR = %s\n", buf);
		memset(buf, s, size);
		printf("OR      = %s\n", buf);
	}
	return (1);
}
*/