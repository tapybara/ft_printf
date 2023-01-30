/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:09:04 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 00:11:11 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1 = (unsigned char *)s1;
	const unsigned char	*str2 = (unsigned char *)s2;

	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "abcde";

	printf("%s : %s\n", "ft", "lib");
	printf("%d : %d\n", ft_memcmp(s1, "abcde", 5), memcmp(s1, "abcde", 5));
	printf("%d : %d\n", ft_memcmp(s1, "abcdd", 5), memcmp(s1, "abcdd", 5));
	printf("%d : %d\n", ft_memcmp(s1, "abcdf", 5), memcmp(s1, "abcdf", 5));
	printf("%d : %d\n", ft_memcmp(s1, "abcdd", 0), memcmp(s1, "abcdd", 0));
	//printf("%d\n", ft_memcmp(s1, NULL, 5));	//segfa
	//printf("%d\n", memcmp(s1, NULL, 5));		//segfa
	//printf("%d\n", ft_memcmp(NULL, s1, 5));	//segfa
	//printf("%d\n", memcmp(NULL, s1, 5));		//segfa
	//printf("%d\n", ft_memcmp(s1, s1, NULL));	//Error(Review check)
	//printf("%d\n", memcmp(s1, s1, NULL));		//Error(Review check)
	return (0);
}*/