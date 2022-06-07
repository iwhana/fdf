/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:30:47 by iwhana            #+#    #+#             */
/*   Updated: 2022/04/15 00:09:13 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 5;
	param->is_isometric = 1;
	param->angle = 0.8;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 4;
	param->shift_y = param->win_y / 4;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	hook_event_close(t_dot **matrix)
{
	mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
	free(matrix);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	matrix = read_map(*++argv);
	set_default(*matrix);
	draw(matrix);
	mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
	mlx_hook(matrix[0][0].win_ptr, 17, 0, hook_event_close, matrix);
	mlx_loop(matrix[0][0].mlx_ptr);
}
