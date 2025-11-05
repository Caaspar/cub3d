/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:56:06 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/14 12:44:49 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_regular_file(char *path)
{
	int		fd;
	char	buffer[1];
	ssize_t	r;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	r = read(fd, buffer, 1);
	close(fd);
	if (r == -1)
		return (1);
	return (0);
}

void	read_map_file(char **argv, t_data *data)
{
	if (is_regular_file(argv[1]))
		error(data, "This is a directory !");
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		error_fd(data, 1);
	data->tmp = ft_strdup("");
	if (!data->tmp)
		return ;
	data->str = get_next_line(data->fd);
	if (!data->str)
		return ;
	while (data->tmp)
	{
		free(data->tmp);
		data->tmp = get_next_line(data->fd);
		if (!data->tmp)
			break ;
		data->str = join(data->str, data->tmp);
		if (!data->str)
			return ;
	}
	if (has_empty_line(data->str))
		error(data, "A line in the map is empty");
}

static void	allocate_map_array(t_data *data, int count)
{
	int	j;
	int	i;

	j = 0;
	i = data->map_start;
	data->map = ft_calloc(count + 1, sizeof(char *));
	if (!data->map)
		return ;
	while (data->file[i] && j < count)
	{
		data->map[j] = ft_strdup(data->file[i]);
		if (!data->map[j])
			return ;
		i++;
		j++;
	}
	data->map_end = data->map_start + find_last_line_map(data->map);
}

void	extract_map(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	if (!data->str)
		error(data, "Map is empty");
	data->file = ft_split(data->str, '\n');
	if (!data->file)
		error(data, "Error in parsing (0)");
	while (data->file[++i])
	{
		if (first_line_map(data->file[i]))
		{
			data->map_start = i;
			count = 0;
			while (data->file[i] && is_line_map(data->file[i++]))
				count++;
			i = data->map_start;
			allocate_map_array(data, count);
			break ;
		}
	}
	if (data->map_start == -1)
		error(data, "No map found!");
	close(data->fd);
}

void	reading_map(char **argv, t_data *data)
{
	read_map_file(argv, data);
	extract_map(data);
}
