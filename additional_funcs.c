/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:20:03 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:20:04 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_size(char **s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int		add_room(t_data *data, char *name, t_coord coord)
{
	t_room *cur;

	cur = data->rooms;
	if (cur != NULL)
	{
		while (cur->next != NULL)
			cur = cur->next;
		if (!(cur->next = init_room(cur->index + 1, name,
			&coord, data->cur_comment)))
			return (-7);
	}
	else
	{
		if (!(data->rooms = init_room(0, name, &coord, data->cur_comment)))
			return (-7);
	}
	data->room_count += 1;
	return (1);
}

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
