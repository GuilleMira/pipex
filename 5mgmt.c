/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5mgmt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:31:20 by guilmira          #+#    #+#             */
/*   Updated: 2021/12/06 11:37:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** PURPOSE : Output error with given value 1, close the program.
 * If exit signal is 0, it will prevent the appeareance of message:
 * "make: *** [exe] Error 1" */
void	ft_shut(char *str, int i)
{
	write(1, str, ft_strlen(str));
	exit(i);
}

/** PURPOSE : clears linked list from first element to last, including content
 * Also frees internal struct memory. */
void	ft_structclear(t_list *lst)
{
	t_list	*tmp;
	t_command	*command_struct;

	if (!lst)
		return ;
	tmp = NULL;
	command_struct = NULL;
	while (lst)
	{
		tmp = lst->next;
		command_struct = lst->content;
		if (lst->content)
		{
			ft_free_split(command_struct->command);
			if (command_struct->path)
				free(command_struct->path);
			free(command_struct);
			free(lst);
		}
		lst = tmp;
	}
}

/** PURPOSE : Free memory of program and close file descriptors.
 * For the function to properly work, all pointers have been
 * initialized to NULL at the beginning of the program. */
void	free_heap_memory(t_arguments *args)
{
	if (args)
	{
		if (args->commands_lst)
			ft_structclear(args->commands_lst);
		if (args->fds)
			free(args->fds);
		free (args);
	}
}

/** PURPOSE : shutdown program freeing heap allocated memory. */
void	ft_shutdown(char *str, int i, t_arguments *args)
{
	free_heap_memory(args);
	ft_shut(str, i);
}