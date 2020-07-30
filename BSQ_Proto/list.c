/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 04:44:53 by sunkim            #+#    #+#             */
/*   Updated: 2019/11/13 21:12:00 by sunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mybsq.h"

void	list_push(char c, t_list *start)
{
	t_list *new;
	t_list *current;

	current = start;
	new = (t_list*)malloc(sizeof(t_list));
	new->data = c;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->next = NULL;
}

t_list	*init_list(void)
{
	t_list *start;

	start = (t_list*)malloc(sizeof(t_list));
	start->next = NULL;
	start->data = '\0';
	return (start);
}

char	list_pop(t_list *start)
{
	char	temp;
	t_list	*current;
	t_list	*before;

	current = start;
	if (current->next == NULL)
		return ('\0');
	while (current->next != NULL)
	{
		if (current->next->next == NULL)
			before = current;
		current = current->next;
	}
	temp = current->data;
	free(current);
	before->next = NULL;
	return (temp);
}

int		bsq_atoi(t_list *start)
{
	t_list	*current;
	int		sum;
	char	temp;

	sum = 0;
	current = start->next;
	if (current == NULL)
		return (0);
	if (current->data < '0' || current->data > '9')
		return (-1);
	sum += current->data - '0';
	while (current->next != NULL)
	{
		sum = sum * 10;
		current = current->next;
		temp = current->data;
		if (temp < '0' || temp > '9')
			return (-1);
		sum += temp - '0';
	}
	return (sum);
}

void	free_all(t_list *start)
{
	t_list *current;
	t_list *temp;

	current = start;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
