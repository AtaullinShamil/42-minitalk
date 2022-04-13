/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:39:07 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 18:44:10 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = count * size;
	str = malloc(i);
	if (!str)
		return (NULL);
	ft_bzero(str, i);
	return (str);
}

//int main()
//{
//	printf("%p\n", ft_calloc(4, 10));
//	printf("%s\n", ft_calloc(4, 10));
//}
