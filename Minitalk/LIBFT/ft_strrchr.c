/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:09 by psanger           #+#    #+#             */
/*   Updated: 2023/10/12 20:49:36 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (ft_strchr(s, (char)c) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			res = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return ((char *)s + res);
}
