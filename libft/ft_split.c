/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:16:29 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/18 18:50:02 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	flag;

	i = 0;
	word = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (flag == 0)
				word++;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	return (word);
}

static void	clear(char **str, size_t str_idx)
{
	size_t	i;

	i = 0;
	while (i < str_idx)
	{
		free (str[i]);
		i++;
	}
	free(str);
}

static int	set_word(char const *s, char c, char **str, size_t str_idx)
{
	char	*src;
	size_t	word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	src = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!src)
	{
		clear (str, str_idx);
		return (0);
	}
	word_len = 0;
	while (s[word_len] && s[word_len] != c)
	{
		src[word_len] = s[word_len];
		word_len++;
	}
	src[word_len] = '\0';
	str[str_idx] = src;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;
	size_t	str_idx;

	if (!s)
		return (0);
	i = 0;
	str_idx = 0;
	str = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!set_word(&s[i], c, str, str_idx++))
				return (0);
		}
		while (s[i] && s[i] != c)
			i++;
	}
	str[str_idx] = 0;
	return (str);
}
