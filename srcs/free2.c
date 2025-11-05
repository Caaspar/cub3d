/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:27:39 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/04 10:29:40 by cgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_char(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		if (s[i])
			free(s[i]);
		i++;
	}
	free (s);
}

int	destroy(t_data *data)
{
	free_all(data);
	exit(0);
}
