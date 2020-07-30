/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:04:29 by tlee              #+#    #+#             */
/*   Updated: 2019/11/06 22:30:37 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	if (NULL != **pp_head)
	{
		p = *pp_head;
		while (NULL != p->p_next)
			p = p->p_next;
		p->p_next = (t_list*)malloc(sizeof(t_list));
		p = p->p_next;
	}
	else
	{
		**pp_head = (t_list*)malloc(sizeof(t_list));
		p = *pp_head;
	}
	p->s_list = data;
	p->p_next = NULL;
}
