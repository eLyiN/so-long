/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:29:57 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/23 14:38:05 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	c_state_0(t_game_bonus *s, mlx_image_t **enemy)
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

void	c_state_1(t_game_bonus *s, mlx_image_t **enemy)
{
	if (enemy[ENEMY_S]->enabled == false)
		enemy[ENEMY_S]->enabled = true;
	s->en_x = (enemy[ENEMY_S]->instances[0].x / 8);
	s->en_y = (enemy[ENEMY_S]->instances[0].y / 8);
	enemy[ENEMY_S]->instances[0].y += 0.1;
	if (s->shlk->lines[s->en_y + 2][s->en_x] == '1')
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

void	c_state_2(t_game_bonus *s, mlx_image_t **enemy)
{
	if (enemy[ENEMY_A]->enabled == false)
		enemy[ENEMY_A]->enabled = true;
	s->en_x = (enemy[ENEMY_A]->instances[0].x / 8);
	s->en_y = (enemy[ENEMY_A]->instances[0].y / 8);
	enemy[ENEMY_A]->instances[0].x -= 0.1;
	if (s->shlk->lines[s->en_y][s->en_x] == '1')
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

void	c_state_3(t_game_bonus *s, mlx_image_t **enemy)
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