/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:58:15 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/03 13:12:59 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	process_map(int32_t fd, t_game *shlk)
{
	shlk->colletibles = 0;
	shlk->end_pos = 0;
	shlk->init_pos = 0;
	if (read_map(fd, shlk))
		error_msg("Empty or invalid map.");
	if (map_rendering(shlk))
		error_msg("The introduce map is incorrect.");
	if (check_walls(shlk))
		error_msg("The map has invalid walls, check the map again please.");
	if (check_objects(shlk))
		error_msg("The map doesn't contain at least one P, C or E.");
	return (0);
}

int32_t	read_map(int32_t fd, t_game *shlk)
{
	int32_t		size_read;
	static char	*buff;

	buff = ft_calloc(10000, sizeof(char));
	if (!buff)
		return (1);
	size_read = 1;
	while (size_read != 0)
	{
		size_read = read(fd, buff, 10000);
		if (size_read == -1)
			return (1);
	}
	shlk->lines = ft_split(buff, '\n');
	shlk->lines_map = count_substr(buff, '\n');
	if (!shlk->lines)
		return (1);
	if (check_invalid_char(shlk))
		return (1);
	free(buff);
	return (0);
}

int32_t	map_rendering(t_game *shlk)
{
	size_t	i;

	i = 0;
	while (shlk->lines[i + 1])
	{
		shlk->lines_size = (int32_t)ft_strlen(shlk->lines[i++]);
		if (shlk->lines_size != (int32_t)ft_strlen(shlk->lines[i]))
			return (1);
	}
	shlk->lines_size = (int32_t)ft_strlen(shlk->lines[0]);
	return (0);
}
