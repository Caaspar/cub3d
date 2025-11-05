/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:32:18 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 11:12:44 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_first_char_valid(t_data *data)
{
	int		i;
	char	c;

	i = 0;
	if (!data || !data->map)
		return (0);
	while (i < data->map_start)
	{
		c = data->file[i++][0];
		if (!c)
			continue ;
		if (is_whitespace(c))
			continue ;
		if (c != 'N' && c != 'W' && c != 'S' && c != 'E'
			&& c != 'F' && c != 'C')
			error(data, "Invalid character in file");
	}
	return (1);
}

int	find_last_line_map(char **map)
{
	int	i;
	int	j;
	int	last_line;

	i = 0;
	last_line = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] == '\0' || !is_valid_map_char(map[i][j]))
			break ;
		last_line = i;
		i++;
	}
	return (last_line);
}

int	check_line(char **line, t_data *data)
{
	int	total_lines;
	int	last_line;

	total_lines = 0;
	while (line[total_lines])
		total_lines++;
	if (!is_map_line(line[data->map_start]))
		return (error(data, "First line is not all walls !"), 0);
	last_line = total_lines - 1;
	if (last_line < data->map_start)
		return (error(data, "Invalid map structure !"), 0);
	if (!is_map_line(line[last_line]))
		return (error(data, "Last line is not all walls !"), 0);
	return (1);
}

int	check_column(char **column, t_data *data)
{
	int	y;
	int	last_char;
	int	max_width;

	max_width = 0;
	y = data->map_start;
	while (column[y])
	{
		last_char = is_map_column(column[y]);
		if (last_char == -1)
		{
			y++;
			continue ;
		}
		if (column[y][0] != '1')
			return (error(data, "First column is not a wall !"), 0);
		if (column[y][last_char] != '1')
			return (error(data, "Last column is not a wall !"), 0);
		if (last_char + 1 > max_width)
			max_width = last_char + 1;
		y++;
	}
	data->rows = max_width;
	data->column = y - data->map_start;
	return (1);
}
