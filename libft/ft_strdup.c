/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:43 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 23:13:29 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_strcpy(char *dst, const char *src)
{
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s) + 1;
	p = (char *)malloc(size * sizeof(char));
	if (p == NULL)
		return (p);
	my_strcpy(p, s);
	return (p);
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

int main(void)
{
	char *s1 = ft_strdup((char*)"coucou");
	char *s2 = strdup((char*)"coucou");
	printf("FT : %d ", strcmp(s1, "coucou"));
	printf("STD: %d\n", strcmp(s2, "coucou"));
}*/