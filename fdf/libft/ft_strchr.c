/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:31:20 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 20:37:34 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)(str + i));
		i++;
	}
	if (ch == 0)
		return ((char *)(str + i));
	return (NULL);
}
