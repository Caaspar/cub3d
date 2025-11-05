/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:59:30 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/04 21:46:36 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_config_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C'
		|| c == 'O' || c == 'A' || (c >= '0' && c <= '9') || c == ' '
		|| c == ',' || c == '.' || c == '/' || c == '_' || c == '-'
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_whitespace(char c)
{
	if (!c)
		return (1);
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || is_whitespace(c));
}

int	line_is_empty(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (!is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_only_whitespace(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (!is_whitespace(line[j]))
			return (0);
		j++;
	}
	return (1);
}
