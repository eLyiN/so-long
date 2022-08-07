/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:42:51 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/08 00:42:56 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
* The map will be charged x2 to have a 4x4 coord in our char, so we can exactly
* know the next position right and precise.
**/

void	init_config(t_game *shlk)
{
	shlk->width = shlk->lines_size / 2 * BLOCK;
	shlk->height = shlk->lines_map / 2 * BLOCK;
	if (shlk->width > 1024 || shlk->height > 1024)
		error_msg(BIG_MAP);
	shlk->mlx = mlx_init(shlk->width, shlk->height, "so_long", true);
	if (!shlk->mlx)
		error_msg("Something goes wrong, try it again.");
}

void	char_hook(void *data)
{
	t_game	*shlk2;
	size_t	x;
	size_t	y;

	shlk2 = data;
	x = (shlk2->img[CHAR]->instances[0].x / 8);
	y = (shlk2->img[CHAR]->instances[0].y / 8);
	if (mlx_is_key_down(shlk2->mlx, MLX_KEY_W) && shlk2->lines[y][x + 1] != '1')
		shlk2->img[CHAR]->instances[0].y -= 0.1;
	if (mlx_is_key_down(shlk2->mlx, MLX_KEY_S) && shlk2->lines[y + 2][x
		+ 1] != '1')
		shlk2->img[CHAR]->instances[0].y += 0.1;
	if (mlx_is_key_down(shlk2->mlx, MLX_KEY_A) && shlk2->lines[y + 1][x] != '1')
		shlk2->img[CHAR]->instances[0].x -= 0.1;
	if (mlx_is_key_down(shlk2->mlx, MLX_KEY_D) && shlk2->lines[y + 1][x
		+ 2] != '1')
		shlk2->img[CHAR]->instances[0].x += 0.1;
	else if (mlx_is_key_down(shlk2->mlx, MLX_KEY_P))
	{
		printf("CHAR[X]=%f\n", shlk2->img[CHAR]->instances[0].x);
		printf("CHAR[Y]=%f\n", shlk2->img[CHAR]->instances[0].y);
		printf("AXE[X]=%ld\n", x);
		printf("AXE[Y]=%ld\n", y);
	}
}

int32_t	init_game(t_game *shlk)
{
	init_config(shlk);
	if (load_images(shlk, shlk->xpm, shlk->img))
		error_msg("Error while loading images, check .xpm42 files");
	windowsize_adapt(shlk);
	object_proyect(shlk, shlk->lines, '1', shlk->img[WALL]);
	object_proyect(shlk, shlk->lines, 'C', shlk->img[COLLEC]);
	object_proyect(shlk, shlk->lines, 'P', shlk->img[CHAR]);
	object_proyect(shlk, shlk->lines, 'E', shlk->img[EXIT]);
	mlx_loop_hook(shlk->mlx, char_hook, shlk);
	mlx_loop(shlk->mlx);
	mlx_terminate(shlk->mlx);
	return (0);
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
		fd = -1;
		while (shlk.lines[fd++])
			printf("LINE%d: %s\n", fd, shlk.lines[fd]);
		if (init_game(&shlk))
			return (1);
		freedom(shlk.lines);
		return (EXIT_SUCCESS);
	}
	error_msg("No map has been introduced.");
}
