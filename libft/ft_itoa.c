/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:15 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/27 22:07:03 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_sort(char **str)
{
	char	temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(*str) - 1;
	while (i <= len / 2)
	{
		temp = (*str)[i];
		(*str)[i] = (*str)[len - i];
		(*str)[len - i] = temp;
		i++;
	}
}

static size_t	get_size(int num)
{
	size_t	count;

	count = 0;
	if (num < 0)
		count++;
	while (num / 10)
	{
		num /= 10;
		count++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		sign;
	size_t	i;

	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (i < size)
	{
		str[i] = sign * (n % 10) + '0';
		n /= 10;
		i++;
		if (sign == -1 && !n)
			str[i++] = '-';
	}
	str[i] = '\0';
	reverse_sort(&str);
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

int main(void)
{
	int	num1 = -623;
	int	num2 = 156;
	int	num3 = -0;
	int num4 = -2147483648;
	printf("%s\n", ft_itoa(num1));
	printf("%s\n", ft_itoa(num2));
	printf("%s\n", ft_itoa(num3));
	printf("%s\n", ft_itoa(num4));
	return (0);
}*/