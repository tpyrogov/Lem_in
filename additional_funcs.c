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

int		init_new_room(t_data *data, char **pars, t_coord *coord)
{
	coord->x = ft_atoi(pars[1]);
	coord->y = ft_atoi(pars[2]);
	if (find_duplicate(data, pars[0], *coord) != NULL)
		return (-12);
	return (add_room(data, pars[0], *coord));
}

void	print_routes(t_data *data)
{
	t_route	*route;
	t_room	*start;
	int		i;

	start = find_by_type(data, 0);
	route = data->routes;
	ft_printf("Found %d routes:\n", data->routes_count);
	while (route != NULL)
	{
		ft_printf("%s->", start->name);
		i = 0;
		while (i < route->depth - 1 && route->route[i + 1] != -1)
		{
			ft_printf("%s->", find_by_index(data, route->route[i])->name);
			i++;
		}
		ft_printf("%s, depth: %d\n",
			find_by_index(data, route->route[i])->name, route->depth);
		route = route->next;
	}
}
