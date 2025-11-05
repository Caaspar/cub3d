/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:11:56 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/11 11:15:48 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*error(t_data *data, char *tmp)
{
	write(2, "\033[31mError\n", 12);
	write(2, tmp, ft_strlen(tmp));
	write(2, "\n\033[0m", 6);
	destroy(data);
	return (0);
}

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		str[j++] = s2[i];
	str[j] = '\0';
	free(s1);
	return (str);
}

int	ft_sochr(char *str, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && s[j] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + j] == s[j] && str[i + j] && s[j])
			j++;
		if (s[j] == '\0' && str[i + j] == '\0')
			return (1);
		else
			j = 0;
		i++;
	}
	return (0);
}

void	error_fd(t_data *data, int value)
{
	if (value == 1)
	{
		perror("\033[31mfile cannot open\033[0m");
		destroy(data);
	}
}

int	ft_atoi_cub(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '-' || str[i] == '+' || (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z'))
		return (-1);
	if (result < 0 || result > 255)
		return (-1);
	return (result);
}
