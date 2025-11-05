/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:39:15 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/07 17:03:10 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	has_relative_space(char **map, int i, int j)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	if (i == 0 || j == 0 || i >= size - 1)
		return (1);
	if (map[i][j + 1] == '\0')
		return (1);
	if (is_whitespace(map[i][j - 1]) || is_whitespace(map[i][j + 1]))
		return (1);
	if (is_whitespace(map[i - 1][j]))
		return (1);
	if (!map[i + 1] || ft_strlen(map[i + 1]) <= (size_t) j)
		return (0);
	if ((map[i + 1] && is_whitespace(map[i + 1][j])))
		return (1);
	return (0);
}

int	check_walled(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c != '1' && !is_whitespace(c))
			{
				if (has_relative_space(data->map, i, j))
				{
					error(data, "The map is not surrounded by walls");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_last_line_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_end_file(t_data *data)
{
	int	total_lines;
	int	i;
	int	j;

	total_lines = 0;
	while (data->file[total_lines])
		total_lines++;
	i = data->map_end + 1;
	while (i < total_lines)
	{
		j = 0;
		while (data->file[i][j] == ' ' || data->file[i][j] == '\t')
			j++;
		if (data->file[i][j] == '0')
			check_walled(data);
		if (data->file[i][j] != '\0' && data->file[i][j] != '\n')
		{
			error(data, "The map must be at the end of the file");
			return (0);
		}
		i++;
	}
	return (1);
}
