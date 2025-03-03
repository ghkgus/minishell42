/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikim2 <yikim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:08:34 by yikim2            #+#    #+#             */
/*   Updated: 2025/01/07 15:44:50 by yikim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

int	word(char *str, char sep)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		while (_sep(str[i], sep) == 1)
			i++;
		if (str[i] != '\0')
			cnt++;
		while (str[i] != '\0' && _sep(str[i], sep) == 0)
			i++;
	}
	return (cnt);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	**youcandoit(char *s, char c, char **icha)
{
	int	word_cnt;
	int	j;
	int	left;
	int	right;

	word_cnt = 0;
	j = 0;
	while (s[word_cnt] != '\0')
	{
		while (s[word_cnt] && _sep(s[word_cnt], c))
			word_cnt++;
		if (s[word_cnt] == '\0')
			return (icha);
		if (s[word_cnt] != '\0' && !_sep(s[word_cnt], c))
			left = word_cnt;
		while (s[word_cnt] && !_sep(s[word_cnt], c))
			right = word_cnt++;
		icha[j] = (char *)malloc(sizeof(char) * (right - left) + 2);
		if (!icha[j])
			return (NULL);
		ft_strncpy(icha[j], &((char *)s)[left], right - left + 1);
		icha[j++][right - left + 1] = '\0';
	}
	return (icha);
}

char	**ft_split(char const *s, char c)
{
	char	**icha;
	int		word_cnt;

	word_cnt = word((char *)s, c);
	icha = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (!icha)
	{
		free(icha);
		return (NULL);
	}
	icha = youcandoit((char *)s, c, icha);
	icha[word_cnt] = 0;
	return (icha);
}