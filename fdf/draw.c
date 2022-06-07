/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:30:47 by iwhana            #+#    #+#             */
/*   Updated: 2022/04/14 22:16:50 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

float	maxi(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	colors(t_dot a, t_dot b)
{
	int	color;

	if (b.z || a.z)
		color = 0xfc0345;
	else
		color = 0xBBFAFF;
	if (b.z != a.z)
		color = 0xfd76fd;
	else
	{
		if (b.z || a.z)
			color = 0xfc0345;
		else
			color = 0xBBFAFF;
	}
	return (color);
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = maxi(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = colors(a, b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], *matrix);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], *matrix);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
