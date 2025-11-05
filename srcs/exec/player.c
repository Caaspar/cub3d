/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:56:39 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/07 11:17:47 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_westeast(t_data *data, char direction)
{
	if (direction == 'W')
	{
		data->dir_y = 0;
		data->dir_x = -1;
		data->plane_y = -0.66;
		data->plane_x = 0;
	}
	else if (direction == 'E')
	{
		data->dir_y = 0;
		data->dir_x = 1;
		data->plane_y = 0.66;
		data->plane_x = 0;
	}
}

void	init_northsouth(t_data *data, char direction)
{
	if (direction == 'N')
	{
		data->dir_y = -1;
		data->dir_x = 0;
		data->plane_y = 0;
		data->plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		data->dir_y = 1;
		data->dir_x = 0;
		data->plane_y = 0;
		data->plane_x = -0.66;
	}
	init_westeast(data, direction);
}

void	location_player(char **loc, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->speed = 0.1;
	while (loc[y])
	{
		x = 0;
		while (loc[y][x])
		{
			if (loc[y][x] == 'N' || loc[y][x] == 'S'
				|| loc[y][x] == 'W' || loc[y][x] == 'E')
			{
				data->pos_y = y + 0.5;
				data->pos_x = x + 0.5;
				init_northsouth(data, loc[y][x]);
				loc[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
