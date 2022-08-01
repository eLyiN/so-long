/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/08/01 11:40:09 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
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
			error_msg("Something goes wrong, try again");
		printf("DENTRO");
	}
	error_msg(WRONG_MAP);
}
