/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:06:13 by aarribas          #+#    #+#             */
/*   Updated: 2022/08/08 00:41:38 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This code has been edited for this proyect, the reason was to make 
/ a 4x4 coords, to proceed with that i just realized to duplicate my ft_split x2
/  in every word and line.
*/

static int	ft_countsubstr(const char *str, char c)
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

static char	*ft_wordcreate(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (((finish - start) * 2) + 1));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i++] = str[start];
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_sub;
	size_t	i;
	size_t	j;
	int		index;

	arr_sub = malloc((ft_countsubstr(s, c) + 1) * sizeof(char *));
	if (!s || !(arr_sub))
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			arr_sub[j++] = ft_wordcreate(s, index, i);
			arr_sub[j++] = ft_wordcreate(s, index, i);
			index = -1;
		}
		i++;
	}
	arr_sub[j] = 0;
	return (arr_sub);
}
