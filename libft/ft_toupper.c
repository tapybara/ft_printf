/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:13:21 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/23 00:02:16 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

/*
#include <stdio.h>
#include <stdlib.h>

char num_to_ascii(int num) {
    if (num >= 0 && num <= 127) {
        return (char)num;
    } else {
        return '\0';
    }
}

int main(void)
{
	int num = '4';
	char c = 'a';

	printf("%c\n", num_to_ascii(ft_toupper(num))); //NULL
	num = atoi(&c);
	printf("%c\n", num_to_ascii(ft_toupper(c))); //A
	return (0);
}*/