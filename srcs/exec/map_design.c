/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:19:47 by caspar            #+#    #+#             */
/*   Updated: 2025/07/07 11:17:41 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_texture	*load_texture(t_data *data, char *path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->img_ptr = mlx_xpm_file_to_image(data->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		free(texture);
		return (NULL);
	}
	texture->data = (int *)mlx_get_data_addr(texture->img_ptr,
			&texture->bpp, &texture->line_length, &texture->endian);
	return (texture);
}

int	*create_texture_buffer(t_texture *tex)
{
	int	*texture_buf;
	int	y;
	int	x;
	int	pos_y;
	int	pos_x;

	texture_buf = malloc(sizeof(int) * TEXTURE_SIZE * TEXTURE_SIZE);
	if (!texture_buf)
		return (NULL);
	y = 0;
	while (y < TEXTURE_SIZE)
	{
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			pos_y = (y * tex->height) / TEXTURE_SIZE;
			pos_x = (x * tex->width) / TEXTURE_SIZE;
			texture_buf[y * TEXTURE_SIZE + x]
				= tex->data[pos_y * tex->width + pos_x];
			x++;
		}
		y++;
	}
	return (texture_buf);
}

int	*load_tex_buffer(t_data *data, char *path)
{
	t_texture	*tmp;
	int			*texture_buf;

	tmp = load_texture(data, path);
	if (!tmp)
		return (NULL);
	texture_buf = create_texture_buffer(tmp);
	mlx_destroy_image(data->mlx, tmp->img_ptr);
	free(tmp);
	return (texture_buf);
}

int	texture_num(t_data *data)
{
	if (data->side_wall == 0)
	{
		if (data->ray_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (data->ray_y > 0)
			return (1);
		else
			return (0);
	}
}

void	init_textures_buffer(t_data *data)
{
	data->imgs = malloc(sizeof(t_imgs));
	if (!data->imgs)
		return ;
	data->imgs->north = load_texture(data, data->north_path);
	data->imgs->south = load_texture(data, data->south_path);
	data->imgs->east = load_texture(data, data->east_path);
	data->imgs->west = load_texture(data, data->west_path);
	if (!data->imgs->north || !data->imgs->south
		|| !data->imgs->east || !data->imgs->west)
	{
		error(data, "error: textures were not loaded");
		return ;
	}
	data->tex_buffer[0] = load_tex_buffer(data, data->north_path);
	data->tex_buffer[1] = load_tex_buffer(data, data->south_path);
	data->tex_buffer[2] = load_tex_buffer(data, data->east_path);
	data->tex_buffer[3] = load_tex_buffer(data, data->west_path);
	if (!data->tex_buffer[0] || !data->tex_buffer[1]
		|| !data->tex_buffer[2] || !data->tex_buffer[3])
	{
		error(data, "error: textures were not loaded in buffer");
		return ;
	}
}
