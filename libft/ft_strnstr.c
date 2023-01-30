/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:23:43 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 19:46:55 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	size_t		haystack_len;
	const char	*haystack_end;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (len > haystack_len)
		len = haystack_len;
	haystack_end = haystack + len - needle_len;
	while (haystack <= haystack_end)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}	
	return (0);
}

int main()
{
	printf("%s : %s\n", "ft", "lib");
	
	// For original tests
	char	*s1 = "MZIRIBMZIRIBMZE123";
	char	*s2 = "bbbbbb";
	size_t	max = 1000;
    printf("%s : %s\n", ft_strnstr(s1, s2, max), strnstr(s1, s2, max));

	// For libftTester-forReloaded
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	printf("%s : %s\n", ft_strnstr(haystack, needle, -1), haystack + 1);
	printf("%s : %s\n", ft_strnstr(haystack, "a", -1), haystack);
	printf("%s : %s\n", ft_strnstr(haystack, "c", -1), haystack + 4);
    
    // printf("%s : %s\n", ft_strnstr(s1, "ab", 5), strnstr(s1, "ab", 5));
    // printf("%s : %s\n", ft_strnstr(s1, "abc", 5), strnstr(s1, "abc", 5));
    // printf("%s : %s\n", ft_strnstr(s1, "abc", 0), strnstr(s1, "abc", 0));
    // printf("haystack=NULL,len=0: %s\n", strnstr(NULL, "abc", 0));
    // printf("haystack=NULL,len=0: %s\n", ft_strnstr(NULL, "abc", 0));
    // printf("haystack=NULL,len=3: %s\n", strnstr(NULL, "fake", 3));
    // printf("haystack=NULL,len=3: %s\n", ft_strnstr(NULL, "fake", 3));
    //printf("%s\n", ft_strnstr("fake", NULL, 3));	//segfa
    //printf("%s\n", strnstr("fake", NULL, 3));		//segfa
    //printf("%s\n", ft_strnstr(a1, a1, NULL));	//Error(Review check)
    //printf("%s\n", strnstr(a1, a1, NULL));	//Error(Review check)
    return (0);
}*/