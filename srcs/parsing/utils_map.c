/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:25:57 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/05 14:15:26 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
			|| line[i] == '\r')
		{
			i++;
			continue ;
		}
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_column(char *line)
{
	int	i;
	int	last_char;

	i = 0;
	last_char = -1;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r')
			last_char = i;
		i++;
	}
	return (last_char);
}

int	first_line_map(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (*line == '1' || *line == '0');
}

int	is_line_map(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0')
		return (0);
	return (*line == '1');
}

int	is_last_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}
