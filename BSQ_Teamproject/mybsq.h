/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mybsq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:02:22 by sunkim            #+#    #+#             */
/*   Updated: 2019/11/13 21:12:02 by sunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYBSQ_H
# define MYBSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

int					convert(int d, char **argv, int **arr, int *var);
int					find_eof(int d, char **argv, int *var);
int					check_valid(int d, char **argv, int *var);
int					find_square(int **arr, int *var);
void				print_array(int **arr, int *var);
int					bsq_atoi(t_list *start);
void				list_push(char c, t_list *start);
char				list_pop(t_list *start);
t_list				*init_list(void);
void				free_all(t_list *start);

#endif
