/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:57:38 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/11 01:08:26 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int32_t	count_substr(const char *str, char c)
{
	int	i;
	int	substr;
	int	in_word;

	i = 0;
	substr = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
				substr++;
			}
			i++;
		}
	}
	return (substr * 2);
}

void	error_msg(char *error)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	freedom(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
