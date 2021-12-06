/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4auxiliar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:04:00 by guilmira          #+#    #+#             */
/*   Updated: 2021/12/06 10:50:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** PURPOSE : Does the path of the command exist? Returns bool. */
int	file_exists(char *str)
{
	int	fp;

	fp = open(str, O_RDONLY);
	if (fp == -1)
		return (0);
	close(fp);
	return (1);
}

/** PURPOSE : Build an int array with every file descriptor of pipes. */
int	*arg_descriptors(t_arguments *args)
{
	int	*ptr;
	int	number_of_fds;

	number_of_fds = (args->total_commands - 1) * 2;
	ptr = ft_calloc(number_of_fds, sizeof(int));
	if (!ptr)
		ft_shutdown(MEM, 0, args);
	return (ptr);
}

/** PURPOSE : Returns content of position 'n' of list.
 * Note: First element of the list is n = 0 */
void	*ft_lst_position(t_list *lst, int n)
{
	int	i;

	i = -1;
	if (!lst)
		return (NULL);
	while (++i < n)
	{
		if (!lst->next)
			return (NULL);
		else
			lst = lst->next;
	}
	return (lst->content);
}
