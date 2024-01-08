/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:04:30 by psanger           #+#    #+#             */
/*   Updated: 2023/10/12 20:49:06 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	j = ft_strlen((char *)s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]) != NULL)
		j--;
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return ((char *)str);
}
