/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:50:05 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/18 00:23:29 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*dst1;
	char	*dst2;
	char	*src;
	size_t	dst_size;
	size_t	cpy_size;
	char	c[256];

	//argv[1]: size of dst-buf
	//argv[2]: copy strings
	//argv[3]: copy size
	dst_size = (size_t)(atoi(argv[1]));
	dst1 = (char *)malloc(sizeof(char) * dst_size); //Prepare ft_dst;
	dst2 = (char *)malloc(sizeof(char) * dst_size); //Prepare or_dst;
	dst1[dst_size] = '\0';
	dst2[dst_size] = '\0';
	src = argv[2];
	cpy_size = (size_t)(atoi(argv[3]));
	if (argc > 4)
		return (0);
	else
	{
		ft_memcpy(dst1, src, cpy_size);
		memcpy(dst2, src, cpy_size);
		printf("ft_memcpy vs memcpy : %d\n", (*dst1 == *dst2));
		printf("ft_memcpy : %s\n", dst1);
		printf("memcpy    : %s\n", dst2);
	}
}
*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	c[256] = "42tokyo";
	printf("ORIGIN: %p\n", ft_memcpy(, NULL, 4));    // 0x0
	printf("ORIGIN: %p\n", memcpy(NULL, NULL, 4));    // 0x0
	printf("ORIGIN: %p\n", memcpy(NULL, NULL, 4));    // 0x0
	printf("FT    : %p\n", ft_memcpy(NULL, NULL, 4)); // 0x0
	printf("ORIGIN: %p\n", memcpy(c, NULL, 4));       // segmentation fault
	printf("FT    : %p\n", ft_memcpy(c, NULL, 4));    // segmentation fault
	printf("ORIGIN: %p\n", memcpy(NULL, c, 4));       // segmentation fault
	printf("FT    : %p\n", ft_memcpy(NULL, c, 4));    // segmentation fault
}
*/