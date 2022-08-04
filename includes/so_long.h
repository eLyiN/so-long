/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:21:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/04 13:48:19 by aarribas         ###   ########.fr       */
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
	STRLIFE,
	STRMOVE,
	COLLEC,
	CHAR,
	DOOR,
	TILE,
	WALL,
	BG,
	EXIT,
	BRICK,
	SCREEN,
	GREY,
	RED,
	IMG_COUNT,
}				t_images;

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
	int32_t		x;
	int32_t		y;
	mlx_image_t	*img[IMG_COUNT];
	xpm_t		*xpm[IMG_COUNT];

}				t_game;

// Main

int32_t			init_game(t_game *shlk);
void			init_config(t_game *shlk);
void			object_proyect(t_game *shlk, char **str, char obj,
					mlx_image_t *img);
void			windowsize_adapt(t_game *shlk);
int32_t			load_images(t_game *shlk, xpm_t **xpm, mlx_image_t **img);

// Map checker
int32_t			check_invalid_char(t_game *shlk);
int32_t			check_walls(t_game *shlk);
int32_t			check_objects(t_game *shlk);
int32_t			check_av_map(char *av);

// Map Rendering

int32_t			process_map(int32_t fd, t_game *shlk);
int32_t			read_map(int32_t fd, t_game *shlk);
int32_t			map_rendering(t_game *shlk);

// Utils

void			freedom(char **str);
int32_t			count_substr(const char *str, char c);
void			error_msg(char *error);

#endif