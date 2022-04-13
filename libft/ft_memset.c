/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:57:44 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:00:33 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len--)
		*str++ = (char)c;
	return (b);
}

//int main()
//{
//	char str[] = "1234567890";
//	void *stp;
//
//	stp = (void *)str;
//	printf("%s\n",stp);
//	printf("%s\n", ft_memset(stp,100,5));
//}
