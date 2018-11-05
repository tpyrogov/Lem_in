/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:19:32 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:19:34 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*init_queue(int index, int i)
{
	t_queue *queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue) * 1)))
		return (NULL);
	queue->index = index;
	queue->i = i;
	queue->next = NULL;
	return (queue);
}

int		add_queue(t_queue **queue, int index, int i)
{
	t_queue *temp;

	if (*queue == NULL)
	{
		if (!(*queue = init_queue(index, i)))
			return (-7);
	}
	else
	{
		temp = *queue;
		while (temp->next != NULL)
			temp = temp->next;
		if (!(temp->next = init_queue(index, i)))
			return (-7);
	}
	return (1);
}

int		check_queue(t_queue *queue, int index)
{
	t_queue *cur;

	cur = queue;
	while (cur)
	{
		if (cur->index == index)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	free_cur_queue(t_queue **queue)
{
	t_queue *temp;

	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}

void	free_map(t_data *data)
{
	t_list *temp;

	temp = data->map;
	while (temp)
	{
		free(temp->content);
		temp = temp->next;
	}
}
