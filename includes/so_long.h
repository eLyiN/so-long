/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:21:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/02 22:37:49 by aarribas         ###   ########.fr       */
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
# define WIDTH 512
# define HEIGHT 512

//Game errors
# define WRONG_MAP "The introduce map is wrong or invalid."

//Game data
typedef enum mlx_images
{
	STRLIFE,
	STRMOVE,
	PICKUP,
	CHAR_R,
	CHAR_L,
	DOOR,
	TILE,
	WALL,
	BG,
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
	int32_t		lines_map;
	mlx_image_t	*img[IMG_COUNT];
	xpm_t		*xpm[IMG_COUNT];

}				t_game;

// Functions

int32_t			init_game(t_game *shlk);
int32_t			check_invalid_char(t_game *shlk);
int32_t			process_map(int32_t fd, t_game *shlk);
void			error_msg(char *error);
int				check_av_map(char *av);
int32_t			count_substr(const char *str, char c);

#endif