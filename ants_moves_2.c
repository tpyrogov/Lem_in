/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_moves_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:53:26 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/03 11:53:27 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_next_ant(t_data *data, int ant_name)
{
	int i;

	i = 0;
	while (i < data->room_count)
	{
		if (data->links[i][i] == ant_name)
			return (i);
		i++;
	}
	return (-1);
}

int		find_in_finish(t_data *data, int ant_name)
{
	int i;

	i = 0;
	while (i < data->routes_count)
	{
		if (data->in_finish_room[i] == ant_name)
		{
			data->in_finish_room[i] = 0;
			return (i);
		}
		i++;
	}
	return (-1);
}

int		only_digits(char *s)
{
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (s[0] == '-')
		i++;
	if (s[i] == '\0')
		return (-1);
	while (i < size)
	{
		if (ft_isdigit(s[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}

void	mark_links(t_data *data, t_room *cur1, t_room *cur2)
{
	if (data->cur_comment != 3 && cur1->type != 4 && cur2->type != 4)
	{
		data->links[cur1->index][cur2->index] = 1;
		if (data->cur_comment != 2)
			data->links[cur2->index][cur1->index] = 1;
	}
	data->cur_comment = -1;
}

int		handle_comments(t_data *data)
{
	if (ft_strcmp(data->buffer, "##start") == 0)
	{
		if (find_by_type(data, 0) != NULL)
			return (-6);
		data->cur_comment = 0;
	}
	else if (ft_strcmp(data->buffer, "##end") == 0)
	{
		if (find_by_type(data, 1) != NULL)
			return (-6);
		data->cur_comment = 1;
	}
	else if (ft_strcmp(data->buffer, "#directed") == 0)
		data->cur_comment = 2;
	else if (ft_strcmp(data->buffer, "#collapse") == 0)
		data->cur_comment = 3;
	else if (ft_strcmp(data->buffer, "#lava") == 0)
		data->cur_comment = 4;
	return (1);
}
