/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:25:21 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/15 23:22:03 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	buf1[atoi(argv[2])];
	char	buf2[atoi(argv[2])];
	size_t	size;
	size_t	i;

	size = (size_t)(atoi(argv[2]));
	if (argc > 3)
		return (0);
	else
	{
		ft_bzero(buf1, size);
		bzero(buf2, size);
		i = 0;
		while (size > i)
		{
			if (buf1[i] != buf2[i])
			{
				printf("Different[%zu]: %d vs %d\n", i, buf1[i], buf2[i]);
				return (0);
			}
			i++;
		}
		printf("Equal");
		return (1);
	}
}
*/