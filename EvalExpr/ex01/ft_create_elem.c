/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:45:29 by tlee              #+#    #+#             */
/*   Updated: 2019/11/10 21:56:09 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

NODE	*ft_create_elem(char data)
{
	NODE *list;

	list = (NODE*)malloc(sizeof*(NODE));
	if (list)
	{
		list->data = data;
		list->p_next = NULL;
	}
	return (list);
}
