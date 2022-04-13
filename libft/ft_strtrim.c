/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:17:00 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:01:05 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	proverka(char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	finish;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	while (s1[start] && proverka(s1[start], set))
		start++;
	finish = ft_strlen(s1);
	while (start < finish && proverka(s1[finish - 1], set))
		finish--;
	str = (char *)malloc(sizeof(char) * ((finish - start) + 1));
	if (!str)
		return (NULL);
	while (start < finish)
	{
		str[i] = s1[start];
		start ++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("12gjksdngdfs12gdsfg12", ""));
// }
