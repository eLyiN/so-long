/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:21:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/23 14:42:11 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//Libraries
# include "so_long.h"

//Game data

typedef enum mlx_enemy
{
	ENEMY_W,
	ENEMY_S,
	ENEMY_A,
	ENEMY_D,
	ENEMY_COUNT,
}				t_enemy_sprite;

typedef struct game_data_bonus
{
	int32_t		enemys;
	int32_t		en_y;
	int32_t		en_x;
	int32_t		en_state;
	t_game		*shlk;
	mlx_image_t	*enemy_img[ENEMY_COUNT];
	xpm_t		*enemy_xpm[ENEMY_COUNT];
	mlx_image_t	*str;
	int32_t		str_state;
	bool		first_time;
}				t_game_bonus;

int32_t			init_bonus_game(t_game *shlk);

int32_t			load_image_enemy(t_game_bonus *s, mlx_image_t **en_img,
					xpm_t **en_xpm);
int32_t			load_enemy(t_game_bonus *s);
void			enemy_rotate(t_game_bonus *s, mlx_image_t **enemy);
void			enemy_reset(t_game_bonus *s, mlx_image_t **enemy);
void			print_moves(t_game_bonus *s);
void			c_state_0(t_game_bonus *s, mlx_image_t **enemy);
void			c_state_1(t_game_bonus *s, mlx_image_t **enemy);
void			c_state_2(t_game_bonus *s, mlx_image_t **enemy);
void			c_state_3(t_game_bonus *s, mlx_image_t **enemy);

#endif