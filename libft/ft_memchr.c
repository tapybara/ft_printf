/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:58:19 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/21 20:06:15 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char a1[] = "abcde";
	
    printf("%s : %s\n", "FT", "STD");
    printf("%p : %p\n", ft_memchr(a1, 'a', 5), memchr(a1, 'a', 5));
    printf("%p : %p\n", ft_memchr(a1, 'c', 5), memchr(a1, 'c', 5));
    printf("%p : %p\n", ft_memchr(a1, 'e', 5), memchr(a1, 'e', 5));
    printf("%p : %p\n", ft_memchr(a1, 'e', 0), memchr(a1, 'e', 0));
    //printf("%p\n", memchr(NULL, 'a', 5));		//segfa
    //printf("%p\n", ft_memchr(NULL, 'a', 5));	//segfa
    //printf("%p\n", memchr(a1, NULL, 5));		//Compile Error(Review check)
    //printf("%p\n", ft_memchr(a1, NULL, 5));	//Compile Error(Review check)
    //printf("%p\n", memchr(a1, a1, NULL));		//Compile Error(Review check)
    //printf("%p\n", ft_memchr(a1, a1, NULL));	//Compile Error(Review check)
    return (0);
}*/