/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:19:36 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/18 21:43:57 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*p++ = c;
	return (b);
}

int	main(void)
{
	char dst[] = "42tokyo";
	char	buf1[0xF00];
	char	buf2[0xF00];

	memset(buf1, 'A', 20);
	memset(buf2, 'A', 20);
	
	printf("dst = %s\n", dst);
	printf("0 ft:%zu - Overflow\n", ft_strlcpy(buf1, "BBBB", sizeof(buf1)));
	printf("0 or:%zu - Overflow\n", strlcpy(buf2, "BBBB", sizeof(buf2)));
	printf("1 ft:%zu\n", ft_strlcpy(dst, "aiueo", 2));
	printf("1 or:%zu\n", strlcpy(dst, "aiueo", 2));
	printf("2 ft:%zu\n", ft_strlcpy(NULL, "aiueo", 0));
	printf("2 or:%zu\n", strlcpy(NULL, "aiueo", 0));
	printf("3 ft:%zu\n", ft_strlcpy(dst, NULL, 0));
	printf("3 or:%zu\n", strlcpy(dst, NULL, 0));
	printf("4 ft:%zu\n", ft_strlcpy(dst, NULL, 2));
	printf("4 or:%zu\n", strlcpy(dst, NULL, 2));
	//printf("ft:%zu\n", ft_strlcpy(NULL, "aiueo", 2));
	//printf("or:%zu\n", strlcpy(NULL, "aiueo", 2));
	//printf("ft:%zu : %s\n", ft_strlcpy(dst, "aiueo", 0), dst);
	//printf("or:%zu\n", strlcpy(dst, "aiueo", 0));
}*/