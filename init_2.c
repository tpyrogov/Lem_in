/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:19:04 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:19:06 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_data(t_data *help)
{
	help->buffer = NULL;
	help->links = NULL;
	help->rooms = NULL;
	help->routes = NULL;
	help->in_finish_room = NULL;
	help->map = NULL;
	help->error_flag = 0;
	help->cur_comment = -1;
	help->ants = 0;
	help->room_count = 0;
	help->init_success = 0;
	help->links_malloced = 0;
	help->depth = -1;
	help->routes_count = 0;
	help->finised_ants = 0;
	help->in_start_room = 0;
	help->new_ant_id = 1;
	help->fin_i = 0;
}

int		init_links(t_data *data)
{
	int i;
	int j;

	i = 0;
	if (!(data->links = (int **)malloc(sizeof(int *) * data->room_count)))
		return (-7);
	while (i < data->room_count)
	{
		if (!(data->links[i] = (int *)malloc(sizeof(int) * data->room_count)))
			return (-7);
		j = 0;
		while (j < data->room_count)
		{
			data->links[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

t_room	*init_room(int index, char *name, t_coord *coord, int type)
{
	t_room	*room;
	size_t	size;

	if (!(room = (t_room *)malloc(sizeof(t_room) * 1)))
		return (NULL);
	room->index = index;
	room->coord.x = coord->x;
	room->coord.y = coord->y;
	size = ft_strlen(name);
	room->type = type;
	room->passed = 0;
	if (!(room->name = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	room->name = ft_strncpy(room->name, name, size);
	room->name[size] = '\0';
	room->next = NULL;
	return (room);
}

t_route	*init_route(int **way, int depth)
{
	t_route *route;

	if (!(route = (t_route *)malloc(sizeof(t_route) * 1)))
		return (NULL);
	route->route = *way;
	route->depth = depth;
	route->next = NULL;
	return (route);
}

int		add_route(t_data *data, int **s, int depth)
{
	t_route *cur;

	if (data->routes == NULL)
	{
		if (!(data->routes = init_route(s, depth)))
			return (-7);
	}
	else
	{
		cur = data->routes;
		while (cur->next != NULL)
			cur = cur->next;
		if (!(cur->next = init_route(s, depth)))
			return (-7);
	}
	return (1);
}
