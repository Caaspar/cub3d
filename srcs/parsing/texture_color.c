/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:16:00 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/10 12:55:00 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	texture_parse_2(char *line, t_data *data)
{
	char	*path;

	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		path = ft_strtrim(line + 3, " \n");
		if (!path)
			return (0);
		data->west_path = path;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		path = ft_strtrim(line + 3, " \n");
		if (!path)
			return (0);
		data->east_path = path;
	}
	return (1);
}

int	texture_parse(t_data *data)
{
	char	*path;

	if (!data->line)
		return (0);
	while (*data->line == ' ')
		data->line++;
	if (ft_strncmp(data->line, "NO ", 3) == 0)
	{
		path = ft_strtrim(data->line + 3, " \n");
		if (!path)
			return (0);
		data->north_path = path;
	}
	else if (ft_strncmp(data->line, "SO ", 3) == 0)
	{
		path = ft_strtrim(data->line + 3, " \n");
		if (!path)
			return (0);
		data->south_path = path;
	}
	return (texture_parse_2(data->line, data));
}

int	color_parse(t_data *data, char *match, t_color *color)
{
	if (ft_strncmp(data->line, match, ft_strlen(match)) == 0)
		return (parse_color(data, color));
	return (1);
}

int	parse_config_line(t_data *data, char *line)
{
	data->line = line;
	if (!color_parse(data, "C ", data->ceiling)
		|| !color_parse(data, "F ", data->floor))
	{
		free(line);
		error(data, "Color parsing problem");
		return (0);
	}
	if (!texture_parse(data))
	{
		free(line);
		error(data, "Texture parsing problem");
		return (0);
	}
	free(line);
	return (1);
}

int	parse_line_before_map(t_data *data)
{
	int		i;
	int		start_map;
	char	*line;

	i = 0;
	data->ceiling = create_color();
	data->floor = create_color();
	if (!data->ceiling || !data->floor)
		return (0);
	while (data->str[i])
	{
		start_map = i;
		while (data->str[i] && data->str[i] != '\n')
			i++;
		line = ft_substr(data->str, start_map, i - start_map);
		if (!line)
			return (0);
		if (!parse_config_line(data, line))
			return (free(line), 0);
		if (data->str[i] == '\n')
			i++;
	}
	if (data->color_parsed < 2)
		error(data, "Color parsing problem");
	return (1);
}
