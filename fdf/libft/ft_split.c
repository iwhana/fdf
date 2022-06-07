/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:11:39 by amalia            #+#    #+#             */
/*   Updated: 2021/11/02 19:13:03 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error(char **s, int size)
{
	while (size--)
		free(s[size]);
	free(s);
	return (-1);
}

static int	count_words(char const *s, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == charset || s[i + 1] == '\0') == 1
			&& (s[i] == charset || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, char const *from, char charset)
{
	int	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **split, char const *s, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == charset || s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] == charset || s[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (ft_error(split, word - 1));
			write_word(split[word], s + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (write_split(res, s, c) == -1)
		return (NULL);
	return (res);
}
