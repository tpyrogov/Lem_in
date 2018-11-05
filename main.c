/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:19:24 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:19:25 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/task_info.h>
#include "lem_in.h"

void	print_map(t_data *data)
{
	t_list *temp;

	temp = data->map;
	while (temp)
	{
		ft_printf("%s", temp->content);
		if (ft_strchr(temp->content, '\n') == NULL)
			ft_printf("\n");
		temp = temp->next;
	}
}

int		save_str(t_data *data)
{
	t_list *map;

	if (data->map == NULL)
	{
		if (!(data->map = ft_lstnew(data->buffer, ft_strlen(data->buffer))))
			return (-7);
	}
	else
	{
		if (!(map = ft_lstnew(data->buffer, ft_strlen(data->buffer))))
			return (-7);
		ft_lstaddback(&data->map, &map);
	}
	return (1);
}

int		*new_int_array(size_t size)
{
	int *new;
	int i;

	i = 0;
	if (!(new = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		new[i] = -1;
		i++;
	}
	return (new);
}

void	flag(t_data *data, char **argv)
{
	if (ft_strcmp(argv[1], "--error") == 0
		|| ft_strcmp(argv[1], "-e") == 0)
		data->error_flag = 1;
	else
	{
		ft_printf("usage: ./lem_in [ -e | --error ]\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_data	help;
	int		error;

	init_data(&help);
	if (argc > 1)
		flag(&help, argv);
	if ((error = init(&help)) < 0
		|| help.init_success != 1
		|| (error = solve(&help)) < 0)
	{
		put_errors(error, &help);
		free_data(&help);
		system("leaks lem_in");
		exit(0);
	}
	print_map(&help);
	free_map(&help);
	ft_printf("\n");
	let_ants_out(&help);
	free_data(&help);
	exit(0);
}
