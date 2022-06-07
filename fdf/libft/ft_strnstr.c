/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:11:34 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 21:27:05 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i + j]) && (little[j])
			&& (i + j < len) && (big[i + j] == little[j]))
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
