/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:42:55 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/11 01:08:03 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	xpm[EXIT] = mlx_load_xpm42("./textures/exit.xpm42");
	img[EXIT] = mlx_texture_to_image(shlk->mlx, &xpm[EXIT]->texture);
	if (!xpm[EXIT] || !img[EXIT])
		return (EXIT_FAILURE);
	xpm[CHAR] = mlx_load_xpm42("./textures/char.xpm42");
	img[CHAR] = mlx_texture_to_image(shlk->mlx, &xpm[CHAR]->texture);
	if (!xpm[CHAR] || !img[CHAR])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	object_proyect(t_game *sh, char **s, char ob, mlx_image_t *img)
{
	size_t	i;
	size_t	j;

	sh->x = 0;
	sh->y = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == ob)
				mlx_image_to_window(sh->mlx, img, sh->x, sh->y);
			sh->x += BLOCK;
			j += 2;
		}
		i += 2;
		sh->y += BLOCK;
		sh->x = 0;
	}
}
