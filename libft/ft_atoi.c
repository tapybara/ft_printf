/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:57:59 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 20:02:03 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	preprocess(const char **str, int *sign)
{
	while (**str == ' ' || ('\t' <= **str && **str <= '\r'))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	preprocess(&str, &sign);
	while (*str != '\0' && ft_isdigit(*str))
	{
		if (num > LONG_MAX / 10
			|| (num == LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else if (sign == -1)
				return ((int)LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}

/*
#include <stdio.h>

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int main(void)
{
	char s1[] = "     -29847";
	char s2[] = "     -29847";
	char s3[] = "     \t\v\f\r\n \f-06050";
	char s4[] = "945";
	char s5[] = "+1234";

	printf("FT %d :STD %d\n", ft_atoi(s1), atoi(s1));
	printf("FT %d :STD %d\n", ft_atoi(s2), atoi(s2));
	printf("FT %d :STD %d\n", ft_atoi(s3), atoi(s3));
	printf("FT %d :STD %d\n", ft_atoi(s4), atoi(s4));
	printf("FT %d :STD %d\n", ft_atoi(s5), atoi(s5));
	
	// Libft^tester-tokyo: tests
	printf("FT %d :STD %d\n", ft_atoi("+1"), atoi("+1"));
	printf("FT %d :STD %d\n", ft_atoi("+7"), atoi("+7"));
	return (0);
}*/
//Sample
/* ローカル変数でstrを代入してから最後に戻す方法 */
// static void	judge_sign(const char **str, int *sign)
// {
// 	const char *a;
// 	a = *str;
// 	while (*a == ' ' || ('\t' <= *a && *a <= '\r'))
// 		a++;
// 	if (*a == '-' || *a == '+')
// 	{
// 		if (*a == '-')
// 			*sign = -1;
// 			a++;
// 	}
// 	*str = a;
// }