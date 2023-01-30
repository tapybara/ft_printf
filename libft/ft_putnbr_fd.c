/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:57:31 by okuyamataka       #+#    #+#             */
/*   Updated: 2023/01/28 18:45:10 by okuyamataka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == INT_MIN)
		{
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		else
			n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	ft_putchar_fd(n + '0', fd);
}

/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

int main(void)
{
	int		num1 = INT_MIN;
	int		num2 = INT_MAX;
	int		num3 = 1;
	int		num4 = -1;
	int		num5 = 42;
	int		num6 = -42;

	ft_putnbr_fd(num1, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putnbr_fd(num2, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putnbr_fd(num3, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putnbr_fd(num4, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putnbr_fd(num5, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putnbr_fd(num6, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}*/