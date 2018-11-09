/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:45:18 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/08 17:45:22 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*find_room(t_data *data, char *name)
{
	t_room *cur;

	cur = data->rooms;
	while (cur)
	{
		if (ft_strcmp(cur->name, name) == 0)
			return (cur);
		cur = cur->next;
	}
	return (cur);
}

t_room	*find_by_type(t_data *data, int type)
{
	t_room *cur;

	cur = data->rooms;
	while (cur)
	{
		if (cur->type == type)
			return (cur);
		cur = cur->next;
	}
	return (cur);
}

t_room	*find_by_index(t_data *data, int index)
{
	t_room *cur;

	cur = data->rooms;
	while (cur)
	{
		if (cur->index == index)
			return (cur);
		cur = cur->next;
	}
	return (cur);
}

t_room	*find_duplicate(t_data *data, char *s, t_coord coord)
{
	t_room *cur;

	cur = data->rooms;
	while (cur)
	{
		if (ft_strcmp(cur->name, s) == 0
		|| (cur->coord.x == coord.x && cur->coord.y == coord.y))
			return (cur);
		cur = cur->next;
	}
	return (cur);
}
