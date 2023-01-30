/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:06:00 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/28 15:50:03 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sprit_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**free2d(char **str, size_t index)
{
	while (index)
		free(str[index--]);
	free(str);
	return (NULL);
}

static char	**substr_allocate(char **str, char const *s, size_t size, char c)
{
	size_t	index;
	size_t	p;
	size_t	start;
	size_t	end;

	index = 0;
	p = 0;
	while (index < size)
	{
		while (s[p] == c && s[p] != '\0')
			p++;
		start = p;
		while (s[p] != c && s[p] != '\0')
			p++;
		end = p++;
		str[index] = ft_substr(s, start, end - start);
		if (str[index] == NULL)
			return (free2d(str, index));
		index++;
	}
	str[index] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	size;

	if (!s)
		return (NULL);
	size = sprit_count(s, c);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	str = substr_allocate(str, s, size, c);
	return (str);
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

int main(void)
{
	size_t	i;

	//libft-tester-tokyo(1~5)
	char const  *s1 = "hello,world,42,tokyo";
	char	**str1 = ft_split(s1, ',');

	i = 0;
	while (i < ft_strlen(*str1))
	{
		printf("%s\n", str1[i]);
		i++;
	}
	printf("\n");

	//libft-tester-tokyo(1~5)
	char const  *s2 = ",,,hello,,,world,,,42,,,tokyo,,,,";
	char	**str2 = ft_split(s2, ',');

	i = 0;
	while (i < ft_strlen(*str2))
	{
		printf("%s\n", str2[i]);
		i++;
	}
	printf("\n");

}
*/