/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:34:15 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 22:41:57 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (!count || !size)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / count < size)
		return (NULL);
	p = (void *)malloc(count * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}

/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

int main(void)
{
	int	size = 8539;
    void *d1 = ft_calloc(size, sizeof(int));
    void *d2 = calloc(size, sizeof(int));
    void *d3 = ft_calloc(0, 1);
    void *d4 = calloc(0, 1);
    void *d5 = ft_calloc(0, 0);
    void *d6 = calloc(0, 0);
    void *d7 = ft_calloc(1, 1);
    void *d8 = calloc(0, 0);
	
	printf("1 %s\n", (char *)d1);
	printf("1 %s\n", (char *)d2);
	printf("2 %s\n", (char *)d3);
	printf("2 %s\n", (char *)d4);
	printf("3 %s\n", (char *)d5);
	printf("3 %s\n", (char *)d6);
	printf("4 %s\n", (char *)d7);
	printf("4 %s\n", (char *)d8);
	free(d1);
	free(d2);
	free(d3);
	free(d4);
	free(d5);
	free(d6);
}*/