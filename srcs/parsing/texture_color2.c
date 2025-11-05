/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:08:38 by pgerner           #+#    #+#             */
/*   Updated: 2025/07/10 14:31:49 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_content(char **result)
{
	int	i;
	int	j;

	i = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (!is_whitespace(result[i][j]) && result[i][j] != ','
				&& !(result[i][j] >= '0' && result[i][j] <= '9'))
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

int	len_array(char **result)
{
	int	len;

	if (!result)
		return (0);
	len = 0;
	while (result[len])
		len++;
	return (len);
}

int	parse_color2(t_data *data, t_color *color, char **result)
{
	color->r = ft_atoi_cub(result[0]);
	if (color->r < 0)
		return (free_char(result), 0);
	color->g = ft_atoi_cub(result[1]);
	if (color->g < 0)
		return (free_char(result), 0);
	color->b = ft_atoi_cub(result[2]);
	if (color->b < 0)
		return (free_char(result), 0);
	data->color_parsed++;
	free_char(result);
	return (1);
}

int	parse_color(t_data *data, t_color *color)
{
	char	*str;
	char	**result;

	str = ft_strtrim(data->line + 2, " \n");
	if (!str)
		return (0);
	result = ft_split(str, ',');
	free(str);
	if (!result)
		return (0);
	if (!check_content(result))
	{
		free_char(result);
		free(data->line);
		error(data, "There is wrong characters in colors");
	}
	if (len_array(result) != 3)
	{
		free_char(result);
		free(data->line);
		error(data, "There must be three colors");
	}
	return (parse_color2(data, color, result));
}

t_color	*create_color(void)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (0);
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
