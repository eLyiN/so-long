/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:33:13 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/15 21:01:28 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int32_t	init_bonus_game(t_game *shlk)
{
	t_game_bonus	bonus;

	bonus.shlk = shlk;
	bonus.en_state = 0;
	bonus.first_time = true;
	if (load_image_enemy(&bonus, bonus.enemy_img, bonus.enemy_xpm))
		error_msg("Invalid or corrupt .xpm42 file.");
	load_enemy(&bonus);
	object_proyect(shlk, shlk->lines, 'Z', bonus.enemy_img[ENEMY_D]);
	mlx_loop_hook(bonus.shlk->mlx, char_hook, &bonus);
	mlx_loop(shlk->mlx);
	return (EXIT_SUCCESS);
}
