/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:14:12 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/23 14:37:50 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int32_t	load_image_enemy(t_game_bonus *s, mlx_image_t **en_img, xpm_t **en_xpm)
{
	en_xpm[ENEMY_A] = mlx_load_xpm42("./textures/bonus/enemy_a.xpm42");
	en_xpm[ENEMY_S] = mlx_load_xpm42("./textures/bonus/enemy_s.xpm42");
	en_xpm[ENEMY_D] = mlx_load_xpm42("./textures/bonus/enemy_d.xpm42");
	en_xpm[ENEMY_W] = mlx_load_xpm42("./textures/bonus/enemy_w.xpm42");
	if (!en_xpm[ENEMY_A] || !en_xpm[ENEMY_S] || !en_xpm[ENEMY_D]
		|| !en_xpm[ENEMY_W])
		return (1);
	en_img[ENEMY_A] = mlx_texture_to_image(s->shlk->mlx,
											&en_xpm[ENEMY_A]->texture);
	en_img[ENEMY_S] = mlx_texture_to_image(s->shlk->mlx,
											&en_xpm[ENEMY_S]->texture);
	en_img[ENEMY_D] = mlx_texture_to_image(s->shlk->mlx,
											&en_xpm[ENEMY_D]->texture);
	en_img[ENEMY_W] = mlx_texture_to_image(s->shlk->mlx,
											&en_xpm[ENEMY_W]->texture);
	return (0);
}

int32_t	load_enemy(t_game_bonus *s)
{
	int32_t	j;
	int32_t	i;

	i = 2;
	while (s->shlk->lines[i])
	{
		j = 0;
		while (s->shlk->lines[i][j])
		{
			if (s->shlk->lines[i][j] == '0' && s->shlk->lines[i][j + 2] == '0'
				&& s->shlk->lines[i + 2][j + 2] == '0')
			{
				s->shlk->lines[i][j] = 'Z';
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	enemy_rotate(t_game_bonus *s, mlx_image_t **enemy)
{
	s->en_x = (enemy[ENEMY_D]->instances[0].x / 8);
	s->en_y = (enemy[ENEMY_D]->instances[0].y / 8);
	if (s->shlk->lines[s->en_y + 1][s->en_x + 1] != '1' && s->en_state == 0)
		c_state_0(s, enemy);
	if (s->en_state == 1)
		c_state_1(s, enemy);
	if (s->en_state == 2)
		c_state_2(s, enemy);
	if (s->en_state == 3)
		c_state_3(s, enemy);
}
