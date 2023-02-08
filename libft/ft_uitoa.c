/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:14:46 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/02/08 20:15:41 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static void	reverse_sort(char *str)
{
	char	temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= len / 2)
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
	}
}

static size_t	get_size(unsigned int num)
{
	size_t	count;

	count = 0;
	while (num / 10)
	{
		num /= 10;
		count++;
	}
	return (count + 1);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	reverse_sort(str);
	return (str);
}
