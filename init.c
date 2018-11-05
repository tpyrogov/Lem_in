/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:18:50 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:18:52 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_room(t_data *data)
{
	char	**pars;
	int		error;
	t_coord	coord;

	if (data->ants > 0)
	{
		pars = ft_strsplit(data->buffer, ' ');
		if (check_size(pars) != 3 || (pars[0] != NULL && pars[0][0] == 'L'))
		{
			free_mass(pars);
			return (-6);
		}
		if (find_room(data, pars[0]) == NULL && only_digits(pars[1]) == 1
		&& only_digits(pars[2]) == 1)
		{
			coord.x = ft_atoi(pars[1]);
			coord.y = ft_atoi(pars[2]);
			error = add_room(data, pars[0], coord);
		}
		else
			error = -6;
		free_mass(pars);
		data->cur_comment = -1;
	}
	return (error);
}

int		create_links(t_data *data)
{
	t_room	*cur1;
	t_room	*cur2;
	char	**pars;

	if (data->links_malloced == 0)
	{
		if (init_links(data) < 0)
			return (-7);
		data->links_malloced = 1;
	}
	if (data->rooms == NULL)
		return (parse_room(data));
	pars = ft_strsplit(data->buffer, '-');
	if (check_size(pars) > 3 || !(cur1 = find_room(data, pars[0]))
	|| !(cur2 = find_room(data, pars[1])))
	{
		if (pars != NULL)
			free_mass(pars);
		return (-5);
	}
	mark_links(data, cur1, cur2);
	free_mass(pars);
	return (1);
}

int		read_ant_num(t_data *data)
{
	char **split;

	split = ft_strsplit(data->buffer, ' ');
	if ((check_size(split) > 1 && data->ants == 0)
	|| ft_strlen(data->buffer) == 0)
	{
		if (split != NULL)
			free_mass(split);
		return (-1);
	}
	if (!(data->ants = ft_atoi(split[0]))
	|| data->ants < 0 || data->ants > 2147483647
	|| ft_strchr(data->buffer, '-'))
	{
		if (split != NULL)
			free_mass(split);
		return (-1);
	}
	free_mass(split);
	return (1);
}

int		final_check(t_data *data)
{
	if (data->rooms == NULL && data->ants == 0 && data->links == NULL)
		return (-9);
	if (data->rooms == NULL || find_by_type(data, 0) == NULL)
		return (-2);
	if (data->links == NULL)
		return (-4);
	if (find_by_type(data, 1) == NULL)
		return (-3);
	data->init_success = 1;
	return (1);
}

int		init(t_data *data)
{
	int		error;
	char	**pars;

	while (get_next_line(STDIN_FILENO, &data->buffer) > 0
		&& ft_strlen(data->buffer) != 0)
	{
		save_str(data);
		pars = ft_strsplit(data->buffer, ' ');
		if (ft_strchr(data->buffer, '#') && data->buffer[0] == '#')
			error = handle_comments(data);
		else if (data->ants == 0)
			error = read_ant_num(data);
		else if (check_size(pars) > 1)
			error = parse_room(data);
		else if (ft_strchr(data->buffer, '-'))
			error = create_links(data);
		else if (ft_strlen(data->buffer) != 0)
			error = -8;
		if (pars != NULL)
			free_mass(pars);
		if (error < 0)
			return (error);
		ft_strdel(&data->buffer);
	}
	return (final_check(data));
}
