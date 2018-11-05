/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:18:23 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:18:29 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_link(t_data *data, t_room *cur)
{
	int j;
	int found;
	int	link;

	found = -1;
	link = data->room_count * data->room_count;
	j = 0;
	while (j < data->room_count)
	{
		if (data->links[cur->index][j] > 1 && link > data->links[cur->index][j])
		{
			link = data->links[cur->index][j];
			found = j;
		}
		j++;
	}
	if (found != -1)
	{
		data->links[cur->index][found] = 0;
		data->links[found][cur->index] = 0;
	}
	data->depth += 1;
	return (found);
}

int		*find_path(t_data *data)
{
	t_room	*cur;
	int		found;
	int		*res;
	int		i;

	i = 0;
	cur = find_by_type(data, 0);
	res = new_int_array((size_t)data->room_count);
	while (cur->type != 1)
	{
		found = find_link(data, cur);
		if (found == -1)
		{
			free(res);
			return (NULL);
		}
		res[i++] = found;
		cur = find_by_index(data, found);
	}
	return (res);
}

void	cycle(t_data *data, t_room **cur, t_queue **queue, int *i)
{
	int j;

	j = 0;
	while (j < data->room_count)
	{
		if (data->links[(*cur)->index][j] == 1)
		{
			data->links[(*cur)->index][j] = (*queue)->i;
			if (data->links[j][(*cur)->index] == 1)
				data->links[j][(*cur)->index] = (*queue)->i;
			(*cur)->passed = 1;
			(*i)++;
			if (find_by_index(data, j)->type != 0
				&& find_by_index(data, j)->passed == 0)
				add_queue(queue, j, (*i + 1));
		}
		else if (data->links[(*cur)->index][j] > 1)
		{
			data->links[(*cur)->index][j] += 1;
			if (data->links[j][(*cur)->index] > 1)
				data->links[j][(*cur)->index] += 1;
		}
		j++;
	}
}

void	mark_connections(t_data *data)
{
	int		i;
	t_room	*cur;
	t_queue	*queue;

	i = 1;
	cur = find_by_type(data, 1);
	queue = NULL;
	add_queue(&queue, cur->index, 2);
	while (queue != NULL)
	{
		cur = find_by_index(data, queue->index);
		cycle(data, &cur, &queue, &i);
		free_cur_queue(&queue);
	}
}

int		solve(t_data *data)
{
	int *s;

	mark_connections(data);
	while (data->depth != 0)
	{
		data->depth = 0;
		s = find_path(data);
		if (s == NULL)
		{
			break ;
		}
		lock_rooms(data, s);
		add_route(data, &s, data->depth);
		data->routes_count += 1;
	}
	if (data->routes == NULL)
		return (-10);
	return (1);
}
