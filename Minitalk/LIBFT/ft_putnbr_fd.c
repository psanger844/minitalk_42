/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:23:01 by psanger           #+#    #+#             */
/*   Updated: 2023/10/12 21:00:45 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	exeptions(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	str[20];

	i = 0;
	if (n == 0 || n == -2147483648)
		if (exeptions(n, fd) == 0)
			return ;
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		while (n > 0)
		{
			str[i] = (n % 10 + '0');
			n = (n / 10);
			i++;
		}
		while (--i >= 0)
			ft_putchar_fd(str[i], fd);
	}
}
