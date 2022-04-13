/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:44:01 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:00:31 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ds;
	char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*ds++ = *sr++;
	return (dst);
}

//int main()
//{
//	char a[] = "1111111111";
//	char b[] = "7777777777";
//	void *az ;
//	void *bz ;
//
//	az= (void *)a;
//	bz =(void *)b;
//	printf("%s\n",a);
//	printf("%s\n", ft_memcpy(az, bz, 5));
//}
