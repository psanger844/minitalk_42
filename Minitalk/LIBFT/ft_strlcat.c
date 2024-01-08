/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:02:48 by psanger           #+#    #+#             */
/*   Updated: 2023/10/17 12:01:45 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		res;
	size_t	src_len;
	size_t	dst_len;
	char	*s;

	s = (char *)src;
	i = 0;
	res = 0;
	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen((char *)dst);
	if (dstsize > dst_len)
		res = src_len + dst_len;
	else
		res = src_len + dstsize;
	while (dst_len + 1 < dstsize && s[i] != '\0')
	{
		dst[dst_len] = s[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (res);
}
