/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:12:13 by caspar            #+#    #+#             */
/*   Updated: 2025/07/07 15:42:00 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x + data->dir_x * data->speed;
	new_y = data->pos_y + data->dir_y * data->speed;
	if (data->map[(int)data->pos_y][(int)new_x] != '1')
		data->pos_x = new_x;
	if (data->map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

void	backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x - data->dir_x * data->speed;
	new_y = data->pos_y - data->dir_y * data->speed;
	if (data->map[(int)data->pos_y][(int)new_x] != '1')
		data->pos_x = new_x;
	if (data->map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

void	strafe_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x - data->dir_y * data->speed;
	new_y = data->pos_y + data->dir_x * data->speed;
	if (data->map[(int)data->pos_y][(int)new_x] != '1')
		data->pos_x = new_x;
	if (data->map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

void	strafe_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x + data->dir_y * data->speed;
	new_y = data->pos_y - data->dir_x * data->speed;
	if (data->map[(int)data->pos_y][(int)new_x] != '1')
		data->pos_x = new_x;
	if (data->map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
		destroy(data);
	else if (keysym == FORWARD || keysym == KEY_UP)
		forward(data);
	else if (keysym == BACKWARD || keysym == KEY_DOWN)
		backward(data);
	else if (keysym == KEY_LEFT)
		rotate_left(data);
	else if (keysym == KEY_RIGHT)
		rotate_right(data);
	else if (keysym == LEFT)
		strafe_left(data);
	else if (keysym == RIGHT)
		strafe_right(data);
	else
		return (0);
	return (0);
}
