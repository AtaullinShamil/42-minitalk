/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:18:00 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:00:43 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	freedom(char **res, int words)
{
	while (words--)
		free(res[words]);
	return (777);
}

static int	schitalka(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0'
			&& (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	slovo(char *dst, char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
}

static int	stroka(char **res, const char *s, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[word])
				return (freedom(res, word - 1));
			slovo(res[word], s + i, c);
			i = i + j;
			word++;
		}
	}
	return (228);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = schitalka(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	if (stroka(res, s, c) == 777)
		return (NULL);
	return (res);
}

// int main()
// {
// 	char c = '.';
// 	char str[] = "...123..1.1234...11...";
// 	char **src;
// 	int i = 0;

// 	src = ft_split(str,c);
// 	while (i < 5)
// 	{
// 		printf("%s\n", src[i]);
// 		i++;
// 	}

// 	return 0;
// }
