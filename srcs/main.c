/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:10:01 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/14 13:00:47 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_mlx(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
		error(data, "Mlx window failed");
	location_player(data->map, data);
	mlx_loop_hook(data->mlx, cast_ray, data);
	mlx_hook(data->win, 2, 1, on_keypress, data);
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 2)
	{
		data.mlx = mlx_init();
		if (!data.mlx)
			return (1);
		if (!parsing(argv, &data))
			error(&data, "Parsing failed");
		init_textures_buffer(&data);
		if (!data.imgs)
			error(&data, "Texture initialization failed");
		if (data.map != NULL)
			start_mlx(&data);
	}
	else
		error(&data, "Number of arguments is incorrect");
}
