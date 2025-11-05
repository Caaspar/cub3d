/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relatives.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:54:38 by pgerner           #+#    #+#             */
/*   Updated: 2025/07/14 13:01:05 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_i(char **map, int i, int j)
{
	int	offset_i;
	int	found;

	offset_i = 0;
	found = 0;
	while (i + --offset_i >= 0 && ft_strlen(map[i + offset_i]) > (size_t) j)
	{
		if (map[i + offset_i][j] == '1')
			found = 1;
	}
	if (!found)
		return (0);
	offset_i = 0;
	while (map[i + ++offset_i] && ft_strlen(map[i + offset_i]) > (size_t) j)
	{
		if (map[i + offset_i][j] == '1')
			found = 1;
	}
	return (found);
}

int	check_j(char **map, int i, int j)
{
	int	offset_j;
	int	found;

	offset_j = 0;
	found = 0;
	while (j + --offset_j >= 0)
	{
		if (map[i][j + offset_j] == '1')
			found = 1;
	}
	if (!found)
		return (0);
	offset_j = 0;
	while (map[i][j + ++offset_j])
	{
		if (map[i][j + offset_j] == '1')
			found = 1;
	}
	return (found);
}

void	fill_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map)
		return ;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_whitespace(data->map[i][j])
				&& check_i(data->map, i, j) && check_j(data->map, i, j))
				data->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	replace_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_whitespace(data->map[i][j]))
				data->map[i][j] = '1';
			j++;
		}
		i++;
	}
}
