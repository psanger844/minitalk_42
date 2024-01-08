/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:19:43 by psanger           #+#    #+#             */
/*   Updated: 2023/10/17 12:30:08 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*itoa_pt2(long int num, int n_p, char *str, int nbr_len)
{
	int	minus;

	minus = 0;
	str[nbr_len] = '\0';
	nbr_len--;
	if (num == 0)
	{
		str[nbr_len] = '0';
		return (str);
	}
	if (n_p == -1)
	{
		str[0] = '-';
		minus = 1;
	}
	while (nbr_len >= minus)
	{
		str[nbr_len] = num % 10 + '0';
		num = num / 10;
		nbr_len--;
	}
	return (str);
}

int	ft_nbr_len(long int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*str;
	int			n_p;
	int			nbr_len;

	nbr_len = 0;
	n_p = 0;
	num = (long int)n;
	if (num <= 0)
	{
		num = num * -1;
		n_p = -1;
		nbr_len++;
	}
	nbr_len = nbr_len + ft_nbr_len(num);
	str = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str)
		return (NULL);
	return (itoa_pt2(num, n_p, str, nbr_len));
}
