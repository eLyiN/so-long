/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:00:04 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/07 19:36:16 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	check_av_map(char *av)
{
	while (*av)
	{
		if (*av == '.')
		{
			if (!ft_strncmp(av, ".ber\0", 5))
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE);
		}
		av++;
	}
	return (EXIT_FAILURE);
}

int32_t	check_walls(t_game *shlk)
{
	size_t	i;

	i = 0;
	while (shlk->lines[0][i])
	{
		if (shlk->lines[0][i] != '1')
			return (1);
		i++;
	}
	i = 1;
	while (shlk->lines[i])
	{
		if (shlk->lines[i][0] != '1' || shlk->lines[i][shlk->lines_size
			- 1] != '1')
			return (1);
		i++;
	}
	if (ft_strcmp(shlk->lines[0], shlk->lines[(int)shlk->lines_map - 1]))
		return (1);
	return (0);
}

int32_t	check_objects(t_game *shlk)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (shlk->lines[i])
	{
		j = 0;
		while (shlk->lines[i][j])
		{
			if (shlk->lines[i][j] == 'P')
				shlk->init_pos++;
			if (shlk->lines[i][j] == 'C')
				shlk->colletibles++;
			if (shlk->lines[i][j] == 'E')
				shlk->end_pos++;
			j++;
		}
		i++;
	}
	if (shlk->colletibles >= 1 && shlk->end_pos >= 1 && shlk->init_pos >= 1)
		return (0);
	else
		return (1);
}

int32_t	check_invalid_char(t_game *shlk)
{
	int	i;
	int	j;

	i = 0;
	while (i < shlk->lines_map)
	{
		j = 0;
		while (shlk->lines[i][j])
		{
			if (shlk->lines[i][j] == '1' || shlk->lines[i][j] == '0'
				|| shlk->lines[i][j] == 'P' || shlk->lines[i][j] == 'E'
				|| shlk->lines[i][j] == 'C')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
