/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:38:43 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/07 16:15:09 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling_column(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->draw_start)
	{
		mlx_pixel_put(data->mlx, data->win, x, y,
			create_color_map(data->ceiling));
		y++;
	}
}

void	draw_wall_column(t_data *data, int x)
{
	int	y;
	int	texture_x;
	int	texture_y;
	int	color;

	texture_x = (int)(data->wall_x * TEXTURE_SIZE);
	if (texture_x < 0)
		texture_x = 0;
	else if (texture_x >= TEXTURE_SIZE)
		texture_x = TEXTURE_SIZE - 1;
	y = data->draw_start;
	while (y++ < data->draw_end)
	{
		texture_y = ((y - data->draw_start) * TEXTURE_SIZE)
			/ (data->draw_end - data->draw_start);
		if (texture_y < 0)
			texture_y = 0;
		else if (texture_y >= TEXTURE_SIZE)
			texture_y = TEXTURE_SIZE - 1;
		color = data->tex_buffer[texture_num(data)]
		[texture_y * TEXTURE_SIZE + texture_x];
		if (data->side_wall == 1)
			color = (color >> 1) & 0x7F7F7F;
		mlx_pixel_put(data->mlx, data->win, x, y, color);
	}
}

void	draw_floor_column(t_data *data, int x)
{
	int	y;

	y = data->draw_end;
	if (x < 0 || y < 0)
		return ;
	while (y < HEIGHT)
	{
		mlx_pixel_put(data->mlx, data->win, x, y,
			create_color_map(data->floor));
		y++;
	}
}

void	draw_window(t_data *data, int x)
{
	draw_ceiling_column(data, x);
	draw_wall_column(data, x);
	draw_floor_column(data, x);
}
