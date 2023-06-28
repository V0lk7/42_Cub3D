/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_doors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:38:28 by jduval            #+#    #+#             */
/*   Updated: 2023/06/28 13:46:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

t_door	*create_node_door(int x, int y)
{
	t_door	*door;

	door = malloc(sizeof(t_door));
	if (door == NULL)
		return (NULL);
	door->index[X] = x;
	door->index[Y] = y;
	door->statement = CLOSE;
	door->time = 0.0;
	door->next = NULL;
	return (door);
}

void	addfront_node_door(t_door **head, t_door *node)
{
	if (node == NULL)
		return ;
	node->next = (*head);
	(*head) = node;
}
