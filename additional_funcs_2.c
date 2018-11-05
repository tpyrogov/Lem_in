/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:44:19 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/03 11:44:21 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lock_room(t_data *data, int found)
{
	int i;

	i = 0;
	while (i < data->room_count)
	{
		data->links[i][found] = 0;
		data->links[found][i] = 0;
		i++;
	}
}

void	lock_rooms(t_data *data, int *s)
{
	int i;

	i = 0;
	while (s[i] != -1 && find_by_index(data, s[i])->type != 1)
	{
		lock_room(data, s[i]);
		i++;
	}
}

void	zero_links(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->room_count)
	{
		j = 0;
		while (j < data->room_count)
		{
			data->links[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		check_ways(t_data *data, t_route **route)
{
	t_route *cur;
	int		res;
	int		d;

	res = 0;
	cur = data->routes;
	while (cur != *route)
	{
		d = (*route)->depth / cur->depth;
		res += d;
		cur = cur->next;
	}
	if (data->in_start_room - res >= 0)
		return (1);
	return (-1);
}

int		find_smallest(t_data *data)
{
	int i;
	int smallest;

	i = 0;
	smallest = data->ants;
	while (i < data->room_count)
	{
		if (data->links[i][i] < smallest && data->links[i][i] != 0)
			smallest = data->links[i][i];
		i++;
	}
	i = 0;
	while (i < data->routes_count)
	{
		if (data->in_finish_room[i] < smallest && data->in_finish_room[i] != 0)
			smallest = data->in_finish_room[i];
		i++;
	}
	return (smallest);
}
