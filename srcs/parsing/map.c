/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:50:43 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 11:13:10 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	value_line(t_data *data, char *line, int is_map, int *player_count)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (!is_map)
		{
			if (!is_valid_config_char(line[x]))
				error(data, "A value before the map is incorrect !");
		}
		else
		{
			if (!is_valid_map_char(line[x]) || line[x] == '\t')
				error(data, "A value on the map is incorrect !");
			if (line[x] == 'N' || line[x] == 'S'
				|| line[x] == 'E' || line[x] == 'W')
			{
				(*player_count)++;
				if (*player_count != 1)
					error(data, "There must be one player on the map !");
			}
		}
		x++;
	}
}

int	check_value(t_data *data)
{
	int	y;
	int	player_count;

	y = 0;
	player_count = 0;
	while (y <= data->map_end)
	{
		value_line(data, data->file[y], y >= data->map_start, &player_count);
		y++;
	}
	return (1);
}

int	verify_count(t_data *data)
{
	if (data->count_no != 1 || data->count_so != 1 || data->count_we != 1
		|| data->count_ea != 1 || data->count_floor != 1
		|| data->count_ceiling != 1 || data->count_player != 1)
		error(data, "The number of a value is wrong !");
	return (1);
}

void	count_values_in_line(t_data *data, char *line, int is_map)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (ft_strncmp(&line[x], "NO", 2) == 0)
			data->count_no++;
		if (ft_strncmp(&line[x], "SO", 2) == 0)
			data->count_so++;
		if (ft_strncmp(&line[x], "WE", 2) == 0)
			data->count_we++;
		if (ft_strncmp(&line[x], "EA", 2) == 0)
			data->count_ea++;
		if (line[x] == 'F')
			data->count_floor++;
		if (line[x] == 'C')
			data->count_ceiling++;
		if (is_map && (line[x] == 'N' || line[x] == 'S'
				|| line[x] == 'W' || line[x] == 'E'))
			data->count_player++;
		x++;
	}
}

int	check_nb_of_value(t_data *data)
{
	int	y;

	y = 0;
	while (y <= data->map_end)
	{
		count_values_in_line(data, data->file[y], y >= data->map_start);
		y++;
	}
	verify_count(data);
	return (1);
}
