/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:19:42 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:19:46 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_rooms(t_data *data)
{
	t_room *temp;

	while (data->rooms != NULL)
	{
		ft_strdel(&data->rooms->name);
		temp = data->rooms->next;
		free(data->rooms);
		data->rooms = temp;
	}
}

void	free_route(t_data *data)
{
	t_route *temp;

	while (data->routes != NULL)
	{
		if (data->routes->route != NULL)
		{
			free(data->routes->route);
			data->routes->route = NULL;
		}
		temp = data->routes->next;
		free(data->routes);
		data->routes = temp;
	}
}

void	free_links(t_data *data)
{
	int i;

	i = 0;
	while (i < data->room_count)
	{
		free(data->links[i]);
		i++;
	}
	free(data->links);
	data->links = NULL;
}

void	free_data(t_data *data)
{
	if (data->rooms != NULL)
		free_rooms(data);
	if (data->routes != NULL)
		free_route(data);
	if (data->links != NULL)
		free_links(data);
	if (data->buffer != NULL)
		ft_strdel(&data->buffer);
}

void	free_mass(char **mass)
{
	int i;

	i = 0;
	while (mass[i] != 0)
	{
		ft_strdel(&mass[i]);
		i++;
	}
	free(mass);
}
