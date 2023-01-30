/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:57 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 00:18:09 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s + ft_strlen(s);
	while (p >= s)
	{
		if (*p == (char)c)
			return ((char *)p);
		p--;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int main()
{
    char a[] = "aiueo";

    printf("%s : %s\n", "ft", "lib");
    printf("%s : %s\n", ft_strrchr(a, '\0'), strrchr(a, '\0'));
    printf("%s : %s\n", ft_strrchr(a, 'a'), strrchr(a, 'a'));
    printf("%s : %s\n", ft_strrchr(a, 'i'), strrchr(a, 'i'));
    printf("%s : %s\n", ft_strrchr(a, 'u'), strrchr(a, 'u'));
    printf("%s : %s\n", ft_strrchr(a, 'e'), strrchr(a, 'e'));
    printf("%s : %s\n", ft_strrchr(a, 'o'), strrchr(a, 'o'));
    printf("%s : %s\n", ft_strrchr(a, 0), strrchr(a, 0));
    printf("%p : %p\n", ft_strrchr(a, 0), strrchr(a, 0));
    printf("%s : %s\n", ft_strrchr(a, 1), strrchr(a, 1));
    printf("%s : %s\n", ft_strrchr(a, 'z'), strrchr(a, 'z'));
    return (0);
}*/