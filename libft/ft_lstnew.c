/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:18:46 by ntojamur          #+#    #+#             */
/*   Updated: 2021/11/09 19:00:21 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*minipig;

	minipig = (t_list *)malloc(sizeof(*minipig));
	if (!minipig)
		return (NULL);
	minipig -> content = content;
	minipig -> next = NULL;
	return (minipig);
}
