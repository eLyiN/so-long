/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:42:51 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/11 08:58:29 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
* The map will be charged x2 to have a 4x4 coord in our char, so we can exactly
* know the next position right and precise.
**/

void	init_config(t_game *shlk)
{
	shlk->width = shlk->lines_size / 2 * BLOCK;
	shlk->height = shlk->lines_map / 2 * BLOCK;
	shlk->colletibles = shlk->colletibles / 4;
	shlk->collected = 0;
	if (shlk->width > 1024 || shlk->height > 1024)
		error_msg(BIG_MAP);
	shlk->mlx = mlx_init(shlk->width, shlk->height, "so_long", true);
	if (!shlk->mlx)
		error_msg("Something goes wrong, try it again.");
}

int32_t	init_game(t_game *shlk)
{
	init_config(shlk);
	if (load_images(shlk, shlk->xpm, shlk->img))
		error_msg("Failed loading images, files may be corrupt or missing");
	windowsize_adapt(shlk);
	object_proyect(shlk, shlk->lines, '1', shlk->img[WALL]);
	object_proyect(shlk, shlk->lines, 'C', shlk->img[COLLEC]);
	object_proyect(shlk, shlk->lines, 'P', shlk->img[CHAR]);
	object_proyect(shlk, shlk->lines, 'E', shlk->img[EXIT]);
	collec_coords(shlk);
	init_bonus_game(shlk);
	return (0);
}

void	end_game(t_game *shlk)
{
	mlx_close_hook(shlk->mlx, char_hook, shlk);
	mlx_close_window(shlk->mlx);
	mlx_terminate(shlk->mlx);
	freedom(shlk->lines);
	free(shlk->objs);
	exit(EXIT_SUCCESS);
}

int32_t	main(int32_t ac, char *av[])
{
	t_game	shlk;
	int32_t	fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			error_msg("Invalid file.");
		if (check_av_map(av[1]))
			error_msg(WRONG_MAP);
		if (process_map(fd, &shlk))
			error_msg("Invalid map, check if they minimum components are in.");
		if (init_game(&shlk))
			return (1);
		end_game(&shlk);
		return (EXIT_SUCCESS);
	}
	error_msg("No map has been introduced.");
}
