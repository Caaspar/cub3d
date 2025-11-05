/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:49:24 by caspar            #+#    #+#             */
/*   Updated: 2025/07/07 11:17:59 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_data *data)
{
	double	new_dir_x;
	double	new_plane_x;
	double	deg_rotate;

	new_dir_x = data->dir_x;
	new_plane_x = data->plane_x;
	deg_rotate = 0.05;
	data->dir_x = data->dir_x * cos(-deg_rotate)
		- data->dir_y * sin(-deg_rotate);
	data->dir_y = new_dir_x * sin(-deg_rotate) + data->dir_y * cos(-deg_rotate);
	data->plane_x = data->plane_x * cos(-deg_rotate)
		- data->plane_y * sin(-deg_rotate);
	data->plane_y = new_plane_x * sin(-deg_rotate)
		+ data->plane_y * cos(-deg_rotate);
}

void	rotate_right(t_data *data)
{
	double	new_dir_x;
	double	new_plane_x;
	double	deg_rotate;

	new_dir_x = data->dir_x;
	new_plane_x = data->plane_x;
	deg_rotate = 0.05;
	data->dir_x = data->dir_x * cos(deg_rotate) - data->dir_y * sin(deg_rotate);
	data->dir_y = new_dir_x * sin(deg_rotate) + data->dir_y * cos(deg_rotate);
	data->plane_x = data->plane_x * cos(deg_rotate)
		- data->plane_y * sin(deg_rotate);
	data->plane_y = new_plane_x * sin(deg_rotate)
		+ data->plane_y * cos(deg_rotate);
}
