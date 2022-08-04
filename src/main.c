/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/08/04 13:49:52 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_config(t_game *shlk)
{
	shlk->width = shlk->lines_size * BLOCK;
	shlk->height = shlk->lines_map * BLOCK;
	if (shlk->width > 1024 || shlk->height > 1024)
		error_msg(BIG_MAP);
	shlk->mlx = mlx_init(shlk->width, shlk->height, "so_long", true);
	if (!shlk->mlx)
		error_msg("Something goes wrong, try it again.");
}

void	windowsize_adapt(t_game *shlk)
{
	shlk->x = 0;
	shlk->y = 0;
	while (shlk->width > shlk->x && shlk->height > shlk->y)
	{
		while (shlk->x < shlk->width)
		{
			mlx_image_to_window(shlk->mlx, shlk->img[BG], shlk->x, shlk->y);
			shlk->x += BLOCK;
		}
		shlk->y += BLOCK;
		if (shlk->x + 16 == shlk->height)
			break ;
		else
			shlk->x = 0;
	}
}

int32_t	load_images(t_game *shlk, xpm_t **xpm, mlx_image_t **img)
{
	xpm[BG] = mlx_load_xpm42("./textures/bg.xpm42");
	img[BG] = mlx_texture_to_image(shlk->mlx, &xpm[BG]->texture);
	if (!xpm[BG] || !img[BG])
		return (EXIT_FAILURE);
	xpm[WALL] = mlx_load_xpm42("./textures/wall.xpm42");
	img[WALL] = mlx_texture_to_image(shlk->mlx, &xpm[WALL]->texture);
	if (!xpm[WALL] || !img[WALL])
		return (EXIT_FAILURE);
	xpm[COLLEC] = mlx_load_xpm42("./textures/collec.xpm42");
	img[COLLEC] = mlx_texture_to_image(shlk->mlx, &xpm[COLLEC]->texture);
	if (!xpm[COLLEC] || !img[COLLEC])
		return (EXIT_FAILURE);
	xpm[CHAR] = mlx_load_xpm42("./textures/char.xpm42");
	img[CHAR] = mlx_texture_to_image(shlk->mlx, &xpm[CHAR]->texture);
	if (!xpm[CHAR] || !img[CHAR])
		return (EXIT_FAILURE);
	xpm[EXIT] = mlx_load_xpm42("./textures/exit.xpm42");
	img[EXIT] = mlx_texture_to_image(shlk->mlx, &xpm[EXIT]->texture);
	if (!xpm[EXIT] || !img[EXIT])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	object_proyect(t_game *shlk, char **str, char obj, mlx_image_t *img)
{
	size_t	i;
	size_t	j;

	shlk->x = 0;
	shlk->y = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == obj)
				mlx_image_to_window(shlk->mlx, img, shlk->x, shlk->y);
			shlk->x += BLOCK;
			j++;
		}
		i++;
		shlk->x = 0;
		shlk->y += BLOCK;
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
		if (init_game(&shlk))
			return (1);
		freedom(shlk.lines);
		return (EXIT_SUCCESS);
	}
	error_msg("No map has been introduced.");
}
