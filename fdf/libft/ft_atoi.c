/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:27:59 by iwhana            #+#    #+#             */
/*   Updated: 2021/11/02 19:48:06 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max_min(const char *str, unsigned long long res, int sign)
{
	unsigned int	i;

	i = 0;
	if (*str <= '0' && *str >= '9')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (res > 9223372036854775807 || i > 19)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	res;
	int						sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (ft_max_min(str, res, sign));
}
