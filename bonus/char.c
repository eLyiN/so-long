/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:07:56 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/23 14:42:24 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	char_hook(void *s)
{
	t_game_bonus	*sh;
	int32_t			x;
	int32_t			y;
	size_t			i;

	sh = s;
	x = (sh->shlk->img[CHAR]->instances[0].x / 8);
	y = (sh->shlk->img[CHAR]->instances[0].y / 8);
	char_wasd(sh->shlk, x, y);
	char_moves(sh->shlk, x, y);
	enemy_rotate(sh, sh->enemy_img);
	print_moves(sh);
	if (sh->shlk->lines[y][x] == 'C' || sh->shlk->lines[y + 2][x + 2] == 'C')
	{
		i = check_collec(sh->shlk, x, y);
		if (sh->shlk->objs[i].enable == false)
			mlx_set_instance_depth(&sh->shlk->img[COLLEC]->instances[i], -1000);
	}
	if ((sh->shlk->lines[y][x] == 'E' || sh->shlk->lines[y + 1][x] == 'E')
		&& sh->shlk->collected == sh->shlk->colletibles)
		end_game(sh->shlk);
	if (mlx_is_key_down(sh->shlk->mlx, MLX_KEY_ESCAPE) || (sh->en_x == x
			&& sh->en_y == y))
		end_game(sh->shlk);
}

void	char_moves(t_game *s, int32_t x, int32_t y)
{
	if ((mlx_is_key_down(s->mlx, MLX_KEY_W) || mlx_is_key_down(s->mlx,
				MLX_KEY_A) || mlx_is_key_down(s->mlx, MLX_KEY_S)
			|| mlx_is_key_down(s->mlx, MLX_KEY_D)) && (x > s->old_x
			|| x < s->old_x || y > s->old_y || y < s->old_y))
	{
		s->moves++;
		s->old_x = x;
		s->old_y = y;
		if ((s->moves % 2) == 0)
		{
			ft_putstr_fd("movement:", STDOUT_FILENO);
			ft_putnbr_fd((int)s->moves / 2, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
}

void	char_wasd(t_game *sh, int x, int y)
{
	if (mlx_is_key_down(sh->mlx, MLX_KEY_W) && sh->lines[y][x + 1] != '1')
		sh->img[CHAR]->instances[0].y -= 0.1;
	if (mlx_is_key_down(sh->mlx, MLX_KEY_S) && sh->lines[y + 2][x + 1] != '1')
		sh->img[CHAR]->instances[0].y += 0.1;
	if (mlx_is_key_down(sh->mlx, MLX_KEY_A) && sh->lines[y + 1][x] != '1')
		sh->img[CHAR]->instances[0].x -= 0.1;
	if (mlx_is_key_down(sh->mlx, MLX_KEY_D) && sh->lines[y + 1][x + 2] != '1')
		sh->img[CHAR]->instances[0].x += 0.1;
}

int32_t	check_collec(t_game *s, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < (size_t)s->colletibles)
	{
		if (x >= s->objs[i].x_start && x <= s->objs[i].x_end
			&& y >= s->objs[i].y_start && y <= s->objs[i].y_end
			&& s->objs[i].enable == true)
		{
			s->objs[i].enable = false;
			s->collected++;
			return (i);
		}
		i++;
	}
	return (0);
}

void	collec_coords(t_game *s)
{
	size_t	i;

	i = 0;
	s->old_x = (int)s->img[CHAR]->instances[0].x / 8;
	s->old_y = (int)s->img[CHAR]->instances[0].y / 8;
	s->moves = 0;
	s->objs = malloc(sizeof(t_object) * s->colletibles);
	while (i < (size_t)s->colletibles)
	{
		s->objs[i].x_start = (s->img[COLLEC]->instances[i].x / 8) - 1;
		s->objs[i].y_start = (s->img[COLLEC]->instances[i].y / 8) - 1;
		s->objs[i].x_end = (s->img[COLLEC]->instances[i].x / 8) + 2;
		s->objs[i].y_end = (s->img[COLLEC]->instances[i].y / 8) + 2;
		s->objs[i].enable = true;
		i++;
	}
}
