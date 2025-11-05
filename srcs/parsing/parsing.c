/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:54:51 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 11:17:14 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_line_and_empty(char *str, int i, int *previous)
{
	int		j;
	char	*line;

	j = i + 1;
	while (str[j] && str[j] != '\n')
		j++;
	line = ft_substr(str, i + 1, j - i - 1);
	if (!is_line_map(line))
	{
		free(line);
		return (j);
	}
	free(line);
	if (*previous)
		return (-1);
	if (str[j] == '\n' && str[j + 1] == '\n')
		*previous = 1;
	return (j);
}

int	has_empty_line(char *str)
{
	int	i;
	int	previous;
	int	result;

	i = 0;
	previous = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			result = check_line_and_empty(str, i, &previous);
			if (result == -1)
				return (1);
			i = result;
			continue ;
		}
		i++;
	}
	return (0);
}

int	parsing(char **argv, t_data *data)
{
	if (ft_strrchr(argv[1], '/'))
		if (ft_strlen(ft_strrchr(argv[1], '/') + 1) < 5)
			return (error(data, "Map is wrong"), 0);
	if (ft_sochr(argv[1], ".cub") == 0)
		return (error(data, "The map must end with .cub"), 0);
	reading_map(argv, data);
	if (data->file == 0)
		return (error(data, "Can't read the map"), 0);
	if (!check_end_file(data))
		return (0);
	fill_spaces(data);
	if (!check_nb_of_value(data) || !parse_line_before_map(data)
		|| !check_walled(data) || !is_first_char_valid(data)
		|| !check_value(data))
		return (0);
	replace_spaces(data);
	return (1);
}
