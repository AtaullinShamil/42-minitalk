/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:36:52 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:00:59 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] != '\0' && len < dstsize)
		len++;
	i = len;
	while (src[len - i] && len + 1 < dstsize)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}

//  int main(void)
//  {
// 	char src[] = "lorem ipsum dolor sit amet";
//  	char dst[] = "rrrrrrrrrrrrrrr";
//  	printf("%s\n", dst);
//  	printf("%zu\n",ft_strlcat(dst,src,5));
//  	printf("%s\n", dst);
//  }
