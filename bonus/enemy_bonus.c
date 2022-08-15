/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:14:12 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/15 21:10:58 by aarribas         ###   ########.fr       */
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
			if (s->shlk->lines[i][j] == '0')
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
	{
		if (enemy[ENEMY_D]->enabled == false)
			enemy[ENEMY_D]->enabled = true;
		enemy[ENEMY_D]->instances[0].x += 0.1;
		if (s->shlk->lines[s->en_y + 1][s->en_x + 2] == '1')
		{
			s->enemy_img[ENEMY_D]->enabled = false;
			s->en_state = 1;
			if (s->first_time == true)
				mlx_image_to_window(s->shlk->mlx, enemy[ENEMY_S],
						(int32_t)enemy[ENEMY_D]->instances[0].x,
						(int32_t)enemy[ENEMY_D]->instances[0].y);
			else
			{
				enemy[ENEMY_S]->instances[0].y = enemy[ENEMY_D]->instances[0].y;
				enemy[ENEMY_S]->instances[0].x = enemy[ENEMY_D]->instances[0].x;
			}
		}
	}
	if (s->shlk->lines[s->en_y + 2][s->en_x] != '1' && s->en_state == 1)
	{
		if (enemy[ENEMY_S]->enabled == false)
			enemy[ENEMY_S]->enabled = true;
		s->en_x = (enemy[ENEMY_S]->instances[0].x / 8);
		s->en_y = (enemy[ENEMY_S]->instances[0].y / 8);
		enemy[ENEMY_S]->instances[0].y += 0.1;
		if (s->shlk->lines[s->en_y + 3][s->en_x] == '1')
		{
			s->enemy_img[ENEMY_S]->enabled = false;
			s->en_state = 2;
			if (s->first_time == true)
				mlx_image_to_window(s->shlk->mlx, enemy[ENEMY_A],
						(int32_t)enemy[ENEMY_S]->instances[0].x,
						(int32_t)enemy[ENEMY_S]->instances[0].y);
			else
			{
				enemy[ENEMY_A]->instances[0].y = enemy[ENEMY_S]->instances[0].y;
				enemy[ENEMY_A]->instances[0].x = enemy[ENEMY_S]->instances[0].x;
			}
		}
	}
	if (s->en_state == 2)
	{
		if (enemy[ENEMY_A]->enabled == false)
			enemy[ENEMY_A]->enabled = true;
		s->en_x = (enemy[ENEMY_A]->instances[0].x / 8);
		s->en_y = (enemy[ENEMY_A]->instances[0].y / 8);
		enemy[ENEMY_A]->instances[0].x -= 0.1;
		if (s->shlk->lines[s->en_y + 1][s->en_x] == '1')
		{
			s->enemy_img[ENEMY_A]->enabled = false;
			s->en_state = 3;
			if (s->first_time == true)
				mlx_image_to_window(s->shlk->mlx, enemy[ENEMY_W],
						(int32_t)enemy[ENEMY_A]->instances[0].x,
						(int32_t)enemy[ENEMY_A]->instances[0].y);
			else
			{
				enemy[ENEMY_W]->instances[0].y = enemy[ENEMY_A]->instances[0].y;
				enemy[ENEMY_W]->instances[0].x = enemy[ENEMY_A]->instances[0].x;
			}
		}
	}
	if (s->en_state == 3)
	{
		if (enemy[ENEMY_W]->enabled == false)
			enemy[ENEMY_W]->enabled = true;
		s->en_x = (enemy[ENEMY_W]->instances[0].x / 8);
		s->en_y = (enemy[ENEMY_W]->instances[0].y / 8);
		enemy[ENEMY_W]->instances[0].y -= 0.1;
		if (s->shlk->lines[s->en_y][s->en_x + 1] == '1')
		{
			s->enemy_img[ENEMY_W]->enabled = false;
			s->en_state = 0;
			s->first_time = false;
			enemy[ENEMY_D]->instances[0].x = enemy[ENEMY_W]->instances[0].x;
			enemy[ENEMY_D]->instances[0].y = enemy[ENEMY_W]->instances[0].y;
		}
	}
}
