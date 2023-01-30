/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:02:33 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 20:05:57 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;

	while (n--)
	{
		if (*str1 != *str2 || *str1 == '\0' || *str2 == '\0')
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
    printf("%s : %s\n", "ft", "lib");

    //char	*s1 = "\200";
	//char	*s2 = "\0";
    //printf("%d : %d\n", ft_strncmp(s1, s2, 1), strncmp(s1, s2, 1));

    char	*s1 = "atoms\0\0\0\0";
	char	*s2 = "atoms\0abc";
	size_t  size = 8;
    printf("%d : %d\n", ft_strncmp(s1, s2, size), strncmp(s1, s2, size));

	char a1[] = "abcde";
    printf("%d : %d\n", ft_strncmp(a1, "abcde", 5), strncmp(a1, "abcde", 5));
    printf("%d : %d\n", ft_strncmp(a1, "abcdd", 5), strncmp(a1, "abcdd", 5));
    printf("%d : %d\n", ft_strncmp(a1, "abcdf", 5), strncmp(a1, "abcdf", 5));
    printf("%d : %d\n", ft_strncmp(a1, "abcdd", 0), strncmp(a1, "abcdd", 0));
    //printf("%d\n", ft_strncmp(a1, NULL, 5));	//segfa
    //printf("%d\n", strncmp(a1, NULL, 5));		//segfa
    printf("%d\n", strncmp(NULL, a1, 5));		//segfa
    printf("%d\n", ft_strncmp(NULL, a1, 5));	//segfa
    //printf("%d\n", ft_strncmp(a1, a1, NULL));	//Error(Review check)
    //printf("%d\n", strncmp(a1, a1, NULL));	//Error(Review check)
    return (0);
}*/