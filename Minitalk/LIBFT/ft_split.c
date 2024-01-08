/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:57:27 by psanger           #+#    #+#             */
/*   Updated: 2023/11/21 12:54:46 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **str, int wordcount)
{
	while (wordcount >= 0)
	{
		free(str[wordcount]);
		wordcount--;
	}
	free(str);
}

char	**split_1(const char *s, char **str, char c, int word_count)
{
	int	i;
	int	word_len;
	int	k;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[i] != '\0' && k < word_count)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			word_len++;
		}
		str[k] = ft_substr(s, i - word_len, word_len);
		if (str[k] == NULL)
			return (ft_free_split(str, k), NULL);
		k++;
		word_len = 0;
	}
	str[k] = NULL;
	return (str);
}

int	wordcount(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**str;

	if (s == NULL)
		return (NULL);
	word_count = wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (str == NULL)
		return (NULL);
	return (split_1(s, str, c, word_count));
}
