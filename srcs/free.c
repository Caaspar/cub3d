/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:15:02 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/14 12:57:01 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_dir2(t_data *data)
{
	if (data->imgs->east)
	{
		if (data->imgs->east->img_ptr)
			mlx_destroy_image(data->mlx, data->imgs->east->img_ptr);
		free(data->imgs->east);
	}
	if (data->imgs->west)
	{
		if (data->imgs->west->img_ptr)
			mlx_destroy_image(data->mlx, data->imgs->west->img_ptr);
		free(data->imgs->west);
	}
}

void	free_dir(t_data *data)
{
	if (!data->imgs || !data->mlx)
		return ;
	if (data->imgs->north)
	{
		if (data->imgs->north->img_ptr)
			mlx_destroy_image(data->mlx, data->imgs->north->img_ptr);
		free(data->imgs->north);
	}
	if (data->imgs->south)
	{
		if (data->imgs->south->img_ptr)
			mlx_destroy_image(data->mlx, data->imgs->south->img_ptr);
		free(data->imgs->south);
	}
	free_dir2(data);
}

void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	free_dir(data);
	while (i < 4)
	{
		if (data->tex_buffer[i])
			free(data->tex_buffer[i]);
		i++;
	}
	free(data->imgs);
}

void	free_all2(t_data *data)
{
	if (data->tmp)
		free(data->tmp);
	if (data->map)
		free_char(data->map);
	if (data->file)
		free_char(data->file);
	if (data->str)
		free(data->str);
}

void	free_all(t_data *data)
{
	free_all2(data);
	if (data->north_path)
		free(data->north_path);
	if (data->south_path)
		free(data->south_path);
	if (data->east_path)
		free(data->east_path);
	if (data->west_path)
		free(data->west_path);
	if (data->ceiling)
		free(data->ceiling);
	if (data->floor)
		free(data->floor);
	free_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
