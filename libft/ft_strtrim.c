/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:56:51 by hwasong           #+#    #+#             */
/*   Updated: 2024/03/10 13:15:48 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_str(char const word, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == word)
			return (1);
		i++;
	}
	return (0);
}

static size_t	num_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (in_str(s1[start], set))
		start++;
	return (start);
}

static size_t	num_last(char const *s1, char const *set)
{
	size_t	last;

	last = ft_strlen(s1) - 1;
	while (in_str(s1[last], set))
		last--;
	return (last);
}

static void	re_str(size_t start, size_t last, char *str, char const *s1)
{
	size_t	i;

	i = 0;
	while (i < last - start + 1)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	last;
	size_t	start;

	if (!s1)
		return (NULL);
	start = num_start(s1, set);
	last = num_last(s1, set);
	if (start == ft_strlen(s1))
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	else
		str = (char *)malloc(sizeof(char) * (last - start + 2));
	if (!str)
		return (NULL);
	re_str(start, last, str, s1);
	return (str);
}
