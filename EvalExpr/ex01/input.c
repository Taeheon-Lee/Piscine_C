/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:40:51 by tlee              #+#    #+#             */
/*   Updated: 2019/11/10 23:03:42 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	*reset_chararray(char *arr)
{
	int i;

	i = -1;
	while (i++ < 1000)
		arr[i] = 0
}

void	addexp(NODE **pp_head, char data)
{
	NODE *p;

	if (NULL != *pp_head)
	{
		while(NULL != p->p_next)
			p = p->p_next;
		p->p_next = (NODE*)malloc(sizeof(NODE));
		p = p->p_next
	}
	else
	{
		*pp_head = (NODE *)malloc(sizeof(NODE));
		p = *pp_Head;
	}
	p->number = data;
	p->p_next = NULL;
}

char	*input(char *exp)
{
	NODE	*p_head;
	int		i;

	*p_head = NULL;
	i = 0;
	while (exp[i])
	{
		if (exp[i] != ' ')
			addexp(&p_head, exp[i]);
		i++;
	}
	return (p_head);
}

char	*check_paren(**pp_head)
{
	NODE *p;
	NODE *p_start;
	NODE *p_end;
	char	sep[1000];
	int		i;

	i = -1;
	reset_chararray(sep);
	while (p->p_next != 0)
	{
		if (p->data = '(')
			p_start = p;
		else if (p->data = ')')
		{
			p_end = p;
			while(p_start != &p_end)
			{
				sep[++i] = p_start->p_next->data;
				p_start = p_start->p_next;
			}
			break ;
		}
		p = p->p_next;
	}
	return (sep);
}

int		main(void)
{
	char *a;

	a = input("1 + 2 * 3 + (4 - 1) * 3");
	check_paren(&a);
	return(0);
}
