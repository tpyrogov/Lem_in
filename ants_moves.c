/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:19:52 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:19:53 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_out(t_data *data)
{
	int i;
	int j;
	int f;

	i = find_smallest(data);
	f = find_in_finish(data, i);
	while (i < data->new_ant_id)
	{
		j = find_next_ant(data, i);
		if (f >= 0)
		{
			ft_printf("L%d-%s ", i, find_by_type(data, 1)->name);
			data->in_finish_room[f] = 0;
			data->finised_ants++;
		}
		else if (j >= 0)
			ft_printf("L%d-%s ", i, find_by_index(data, j)->name);
		i++;
		f = find_in_finish(data, i);
	}
}

void	move_on(t_data *data, t_route *route)
{
	int i;

	i = route->depth - 1;
	while (i != 0)
	{
		if (data->links[route->route[i - 1]][route->route[i - 1]] != 0
		&& find_by_index(data, route->route[i])->type == 1)
		{
			data->in_finish_room[data->fin_i] =
			data->links[route->route[i - 1]][route->route[i - 1]];
			if (data->fin_i == data->routes_count - 1)
				data->fin_i = 0;
			else
				data->fin_i++;
			data->links[route->route[i - 1]][route->route[i - 1]] = 0;
		}
		else if (data->links[route->route[i - 1]][route->route[i - 1]] > 0)
		{
			data->links[route->route[i]][route->route[i]] =
			data->links[route->route[i - 1]][route->route[i - 1]];
			data->links[route->route[i - 1]][route->route[i - 1]] = 0;
		}
		i--;
	}
}

void	add_new_ant(t_data *data, t_route *route)
{
	if (find_by_index(data, route->route[0])->type == 1)
	{
		data->in_finish_room[data->fin_i] = data->new_ant_id;
		if (data->fin_i == data->routes_count - 1)
			data->fin_i = 0;
		else
			data->fin_i++;
		data->new_ant_id++;
		data->in_start_room--;
	}
	else if (data->links[route->route[0]][route->route[0]] == 0)
	{
		data->links[route->route[0]][route->route[0]] = data->new_ant_id;
		data->new_ant_id++;
		data->in_start_room--;
	}
}

void	print_move(t_data *data)
{
	t_route *route;

	route = data->routes;
	while (route)
	{
		move_on(data, route);
		if (data->in_start_room > 0 && check_ways(data, &route) > 0)
			add_new_ant(data, route);
		route = route->next;
	}
	print_out(data);
}

void	let_ants_out(t_data *data)
{
	int i;

	i = 0;
	zero_links(data);
	data->depth = data->routes->depth;
	data->new_ant_id = 1;
	data->in_finish_room = (int *)malloc(sizeof(int) * data->routes_count);
	while (i < data->routes_count)
		data->in_finish_room[i++] = 0;
	data->in_start_room = data->ants;
	while (data->finised_ants != data->ants)
	{
		print_move(data);
		ft_printf("\n");
	}
}
