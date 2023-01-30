/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:34:33 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/26 00:12:55 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	while (n--)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}

int main()
{
    printf(" 1. aiued : %s\n", ft_substr("aiueoaiued", 5, 10));
    printf(" 2. aiued : %s\n", ft_substr("aiueoaiued", 5, 5));
    printf(" 3. a : %s\n", ft_substr("aiueoaiued", 5, 1));
    printf(" 4. : %s\n", ft_substr("", 5, 1));
    printf(" 5. a : %s\n", ft_substr("aiueoaiued", 0, 1));
    printf(" 6. : %s\n", ft_substr("aiueoaiued", 5, 0));
    printf(" 7. : %s\n", ft_substr("aiueoaiued", 100, 0));
    
	//libft-tester-tokyo
	char *s1 = "libft-test-tokyo";
	printf("10. : %s\n", ft_substr(s1, 20, 100));
    printf("11. : %s\n", ft_substr(s1, 20, 5));
    printf("12. : %s\n", ft_substr(s1, 20, 0));
    return (0);

	//libftTester-forReloaded
	char *s2 = "tripouille";
    printf("13. : %s\n", ft_substr(s2, 0, 42000));
	// mcheck(s, strlen("tripouille") + 1); free(s); showLeaks(); //Error
}*/