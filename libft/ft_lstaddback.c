/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:42:48 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/08 17:42:52 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstaddback(t_list **list, t_list **new)
{
	t_list *temp;

	if (*new)
	{
		if (*list == NULL)
			*list = *new;
		else
		{
			temp = *list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = *new;
		}
	}
}
