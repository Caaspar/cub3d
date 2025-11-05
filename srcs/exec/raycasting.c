/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:46:15 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/07 16:14:48 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	delta_distance(t_data *data)
{
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = fabs(1 / data->ray_x);
	data->delta_dist_y = fabs(1 / data->ray_y);
	if (data->ray_x < 0)
	{
		data->step_x = -1;
		data->dist_ray_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->dist_ray_x = (data->map_x + 1 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_y < 0)
	{
		data->step_y = -1;
		data->dist_ray_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->dist_ray_y = (data->map_y + 1 - data->pos_y) * data->delta_dist_y;
	}
}

void	algo_dda(t_data *data)
{
	while (1)
	{
		if (data->dist_ray_x < data->dist_ray_y)
		{
			data->dist_ray_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side_wall = 0;
		}
		else
		{
			data->dist_ray_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side_wall = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			break ;
	}
}

void	wall_height(t_data *data)
{
	int		line_height;
	double	wall_dist;

	if (data->side_wall == 0)
		wall_dist = (data->map_x - data->pos_x
				+ (1 - data->step_x) / 2) / data->ray_x;
	else
		wall_dist = (data->map_y - data->pos_y
				+ (1 - data->step_y) / 2) / data->ray_y;
	line_height = (int)(HEIGHT / wall_dist);
	data->draw_start = -line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0 || data->draw_start >= HEIGHT)
		data->draw_start = 0;
	data->draw_end = line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
	if (data->side_wall == 0)
		data->wall_x = data->pos_y + wall_dist * data->ray_y;
	else
		data->wall_x = data->pos_x + wall_dist * data->ray_x;
	data->wall_x -= floor(data->wall_x);
}

int	cast_ray(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		data->cam_x = 2 * x / (double)WIDTH - 1;
		data->ray_x = data->dir_x + data->plane_x * data->cam_x;
		data->ray_y = data->dir_y + data->plane_y * data->cam_x;
		delta_distance(data);
		algo_dda(data);
		wall_height(data);
		draw_window(data, x);
		x++;
	}
	return (1);
}
