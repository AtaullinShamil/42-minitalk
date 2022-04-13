/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:19:07 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:01:06 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;
	size_t	i;

	if (!s)
		return (NULL);
	new_len = ft_strlen(s) - start;
	i = 0;
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len <= new_len)
		new_len = len;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < new_len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
// 	else if (len > new_len)
// 	{
// 		str = (char *)malloc(sizeof(char) * (new_len + 1));
// 		if (!str)
// 			return (NULL);
// 		while (s[i] && i < new_len)
// 			str[i++] = s[start++];
// 		str[i] = '\0';
// 		return (str);
// 	}
// 	else
// 	{
// 		str = (char *)malloc(sizeof(char) * (len + 1));
// 		if (!str)
// 			return (NULL);
// 		while (s[i] && i < len)
// 			str[i++] = s[start++];
// 		str[i] = '\0';
// 		return (str);
// 	}
// }

// int	main(void)
// {
// 	char s[] = "asdfdsafasdf777fadfafsda";

// 	printf ("%s\n", ft_substr(s, 55, 3));
// 	return (0);
// }
