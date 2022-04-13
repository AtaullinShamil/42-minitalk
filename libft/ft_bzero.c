/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:12:33 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 18:59:31 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		*str++ = '\0';
}

//int main()
//{
//	char str[] = "1234567890";
//	printf("%s\n", str);
//	ft_bzero(str,5);
//	printf("%s\n", str);
//	str[0] = '1';
//	printf("%s\n", str);
//	str[5] = '1';
//	printf("%s\n", str);
//}
