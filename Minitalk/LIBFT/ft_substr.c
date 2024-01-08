/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:17:38 by psanger           #+#    #+#             */
/*   Updated: 2023/10/16 11:16:11 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen((char *)s);
	if (!s)
		return (0);
	if (len + start > s_len)
		len = s_len - start;
	if (start > s_len)
		len = 0;
	sub = (char *)malloc(sizeof (char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
