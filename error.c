/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:18:39 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:18:40 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_with_buff(int error, t_data *data)
{
	if (error == -5)
		ft_printf("There is an error in your links!\nCheck them, please");
	else if (error == -6)
		ft_printf("There is an error in your rooms!\nCheck them, please");
	else if (error == -8)
		ft_printf("Unknown data");
	else if (error == -11)
		ft_printf("Wrong room declaration!\nMove it to your rooms block");
	else if (error == -12)
		ft_printf("Room duplicate");
	ft_printf(": %s", data->buffer);
}

void	flag_errors(int error, t_data *data)
{
	if (error == -1)
		ft_printf("Check your numbers of ants!");
	else if (error == -2)
		ft_printf("You forgot to mark start room!");
	else if (error == -3)
		ft_printf("You forgot to mark end room!");
	else if (error == -4)
		ft_printf("There is no links between rooms!");
	else if (error == -7)
		ft_printf("Couldn't allocate memory, sorry(");
	else if (error == -9)
		ft_printf("No data, check carefully your map.");
	else if (error == -10)
		ft_printf("Can't build any route, check your map!");
	else
		print_with_buff(error, data);
}

void	put_errors(int error, t_data *data)
{
	ft_printf("ERROR");
	if (data->error_flag == 1)
	{
		ft_printf(": ");
		flag_errors(error, data);
	}
	ft_printf("\n");
}
