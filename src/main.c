/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/08/01 15:19:37 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static mlx_image_t	*g_img;

int	check_av_map(char *av)
{
	while (*av)
	{
		if (*av == '.')
		{
			if (!ft_strncmp(av, ".ber\0", 5))
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE);
		}
		av++;
	}
	return (EXIT_FAILURE);
}

void	error_msg(char *error)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_D))
		g_img->instances[0].x += 5;
}

int	main(int ac, char *av[])
{
	mlx_t	*mlx;

	if (ac == 2)
	{
		printf("av[1]:%s\n", av[1]);
		if (check_av_map(av[1]))
			error_msg(WRONG_MAP);
		mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
		if (!mlx)
			error_msg("Something goes wrong, try again.");
		g_img = mlx_new_image(mlx, 128, 128);
		ft_memset(g_img->pixels, 255, g_img->width * g_img->height
				* sizeof(int));
		mlx_image_to_window(mlx, g_img, 0, 0);
		mlx_loop_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
