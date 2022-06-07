/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:32:30 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 20:42:49 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*src;
	char	*p;
	int		i;

	i = 0;
	while (str[i])
		i++;
	src = malloc(i + 1);
	if (!src)
		return (NULL);
	p = src;
	while (*str)
		*p++ = *str++;
	*p = '\0';
	return (src);
}
