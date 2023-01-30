/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:13:03 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/28 00:02:55 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_startpoint(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	get_endpoint(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[(len - 1) - i]) == NULL)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	size_t	start;
	size_t	end;
	size_t	trimed_size;

	if (!s1)
		return (NULL);
	trimed_size = 1;
	start = get_startpoint(s1, set);
	end = get_endpoint(s1, set);
	if (end >= start)
		trimed_size = end - start + 1;
	trimed_str = (char *)malloc(sizeof(char) * trimed_size);
	if (!trimed_str)
		return (NULL);
	ft_strlcpy(trimed_str, s1 + start, trimed_size);
	return (trimed_str);
}

/*
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const unsigned char	*src_cpy;

	if (dstsize == 0)
		return (ft_strlen(src));
	src_cpy = (unsigned const char *)src;
	while (*src_cpy != '\0' && (dstsize--) - 1)
	{
		*dst++ = *src_cpy++;
	}
	*dst = '\0';
	return (ft_strlen(src));
}

#include <stdio.h>
#define TRIM_SET_PLACEHOLDER " \n\t"

int main(void)
{
	// libft-tester-tokyo
	printf("[hello ]:[%s]\n", ft_strtrim("hello world", "world"));
	printf("[ world]:[%s]\n", ft_strtrim("hello world", "hello"));
	printf("[hello world]:[%s]\n", ft_strtrim("hello world", ""));
	printf("[hello world]:[%s]\n", ft_strtrim("    hello world     ", " "));
	printf("[ ]:[%s]\n", ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz"));
	// libft-unit-test
	printf("[]:[%s]\n", ft_strtrim("  \t \t \n   \n\n\n\t", TRIM_SET_PLACEHOLDER));
	printf("[]:[%s]\n", ft_strtrim(NULL, TRIM_SET_PLACEHOLDER));
}
*/