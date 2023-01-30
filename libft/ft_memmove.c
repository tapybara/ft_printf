/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:14:00 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/20 22:44:58 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (len--)
			*dst_cpy++ = *src_cpy++;
	}
	else if (dst > src)
	{
		while (len--)
			dst_cpy[len] = src_cpy[len];
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	//argv[1]: dst-strings
	//argv[2]: src-strings
	//argv[3]: copy length(bytes)

	char	*dst1;
	char	*dst2;
	char	*src;
	size_t	dst_size;
	size_t	cpy_size;

	dst_size = (size_t)(atoi(argv[3]));
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
		ft_memmove(dst1, src, cpy_size);
		memmove(dst2, src, cpy_size);
		printf("src        : %s\n", src);
		printf("ft_memmove vs memmove : %d\n", (*dst1 == *dst2));
		printf("ft_memmove : %s\n", dst1);
		printf("memmove    : %s\n", dst2);
	}
}
*/
/*
#include <stdio.h>
#include <string.h>
<sys/mman.h>

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

int	main(void)
{
	//For integers
	//unsigned long	src = 0xdeadbeef;
	//int	size = sizeof(src);
	//unsigned long	dst1;
	//unsigned long	dst2;
	
	//printf("ORIGIN: %s -integers\n", (char *)memmove(&dst1, &src, size));
	//printf("FT    : %s -integers\n", (char *)ft_memmove(&dst2, &src, size));
	
	//For overlap
	//char	c[7] = "42tokyo";
	//char	dst1[0xF0];
	//char	dst2[0xF0];
	//char	*data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	//int		size = 0xF0 - 0xF;

	//memset(dst1, 'A', sizeof(dst1));
	//memset(dst2, 'A', sizeof(dst2));	
	//memcpy(dst1, data, strlen(data));
	//memcpy(dst2, data, strlen(data));

	//printf("ORIGIN: %s -Overlap1\n", (char *)memmove(dst1 + 3, dst1, size));
	//printf("FT    : %s -Overlap1\n", (char *)ft_memmove(dst2 + 3, dst2, size));
	
	//For ******
	//int		size = 128 * 1024 * 1024;
	//char	*dst = (char *)malloc(sizeof(char) * size);
	//char	*data = (char *)malloc(sizeof(char) * size);

	//memset(data, 'A', size);
	//if (!dst)
	//	exit(TEST_INVISIBLE);
	//ft_memmove(dst, data, size);
	//exit(TEST_SUCCESS);

	//For ******

	int		size = 10;
	char	*dst = electric_alloc(size);
	char	*data = electric_alloc(size);

	memset(data, 'A', size);

	mprotect(dst - 4096 + size, 4096, PROT_WRITE);
	mprotect(data - 4096 + size, 4096, PROT_READ);
	
	ft_memmove(dst, data, size);

	dst = electric_alloc_rev(size);
	data = electric_alloc_rev(size);

	memset(data, 'A', size);

	mprotect(dst- size, 4096, PROT_WRITE);
	mprotect(data - size, 4096, PROT_READ);

	ft_memmove(dst, data, size);

	//printf("FT    : %s\n", (char *)ft_memmove(c, c+1, 4)); // 0x0
	//printf("ORIGIN: %s\n", (char *)memmove(c, c+1, 4));    // 0x0
	//printf("FT    : %s\n", (char *)ft_memmove(c+1, c, 4)); // 0x0
	//printf("ORIGIN: %s\n", (char *)memmove(c+1, c, 4));    // 0x0
	//printf("FT    : %s\n", (char *)ft_memmove(c, c, 4)); // 0x0
	//printf("ORIGIN: %s\n", (char *)memmove(c, c, 4));    // 0x0

	//printf("ORIGIN: %p\n", memmove(NULL, NULL, 4));    // 0x0
	//printf("FT    : %p\n", ft_memmove(NULL, NULL, 4)); // 0x0
	//printf("ORIGIN: %p\n", memmove(NULL, c, 4));       // segf
	//printf("FT    : %p\n", ft_memmove(NULL, c, 4));    // segfault
	//printf("ORIGIN: %p\n", memmove(c, NULL, 4));       // segfault
	//printf("FT    : %p\n", ft_memmove(c, NULL, 4));    // segfault
}*/