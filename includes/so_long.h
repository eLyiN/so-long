/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:21:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/10 08:57:49 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Libraries
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

//Game parameters
# define BLOCK 16

//Game errors
# define WRONG_MAP "The introduce map is wrong or invalid."
# define BIG_MAP "The map is too big.(MAX : 1024 characters)"

//Game data

typedef enum mlx_images
{
	COLLEC,
	CHAR,
	WALL,
	BG,
	EXIT,
	IMG_COUNT,
}				t_images;

typedef struct object
{
	size_t		x_start;
	size_t		x_end;
	size_t		y_start;
	size_t		y_end;
	bool		enable;
}				t_object;

typedef struct game_data
{
	mlx_t		*mlx;
	int32_t		width;
	int32_t		height;
	char		**lines;
	int32_t		lines_size;
	int32_t		lines_map;
	int			colletibles;
	int			init_pos;
	int			end_pos;
	int			collected;
	int32_t		old_x;
	int32_t		old_y;
	int32_t		x;
	int32_t		y;
	size_t		moves;
	mlx_image_t	*img[IMG_COUNT];
	xpm_t		*xpm[IMG_COUNT];
	t_object	*objs;
}				t_game;

// Main

int32_t			init_game(t_game *shlk);
void			init_config(t_game *shlk);
void			object_proyect(t_game *sh, char **s, char ob, mlx_image_t *img);
void			windowsize_adapt(t_game *shlk);
int32_t			load_images(t_game *shlk, xpm_t **xpm, mlx_image_t **img);
void			end_game(t_game *shlk);

// Map checker
int32_t			check_invalid_char(t_game *shlk);
int32_t			check_walls(t_game *shlk);
int32_t			check_objects(t_game *shlk);
int32_t			check_av_map(char *av);
int32_t			check_obstacle(t_game *shlk);

// Map Rendering

int32_t			process_map(int32_t fd, t_game *shlk);
int32_t			read_map(int32_t fd, t_game *shlk);
int32_t			map_rendering(t_game *shlk);

// Utils

void			freedom(char **str);
int32_t			count_substr(const char *str, char c);
void			error_msg(char *error);

// Char control

void			char_hook(void *s);
int32_t			check_collec(t_game *s, size_t x, size_t y);
void			collec_coords(t_game *s);
void			char_wasd(t_game *sh, int x, int y);
void			char_moves(t_game *s, int32_t x, int32_t y);

#endif