/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:19:14 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/02 17:19:16 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_room
{
	int				index;
	int				passed;
	int				type;
	char			*name;
	t_coord			coord;
	struct s_room	*next;
}					t_room;

typedef struct		s_route
{
	int				index;
	int				depth;
	int				*route;
	struct s_route	*next;
}					t_route;

typedef struct		s_queue
{
	int				index;
	int				i;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_data
{
	t_list			*map;
	char			*buffer;
	int				error_flag;
	int				*in_finish_room;
	int				fin_i;
	int				finised_ants;
	int				new_ant_id;
	int				in_start_room;
	int				ants;
	int				room_count;
	int				routes_count;
	int				**links;
	t_room			*rooms;
	t_route			*routes;
	int				cur_comment;
	int				links_malloced;
	int				init_success;
	int				rooms_inited;
	int				print_routes;
	int				depth;
}					t_data;

int					init(t_data *data);
t_room				*init_room(int index, char *name, t_coord *coord, int type);
int					init_links(t_data *data);
void				init_data(t_data *help);
t_route				*init_route(int **way, int depth);
int					add_route(t_data *data, int **s, int depth);
int					*new_int_array(size_t size);

int					init_new_room(t_data *data, char **pars, t_coord *coord);

int					check_size(char **s);
int					add_room(t_data *data, char *name, t_coord coord);
t_room				*find_room(t_data *data, char *name);
t_room				*find_by_type(t_data *data, int type);
t_room				*find_by_index(t_data *data, int index);
t_room				*find_duplicate(t_data *data, char *s, t_coord coord);

void				put_errors(int error, t_data *data);

int					solve(t_data *data);
void				mark_connections(t_data *data);
void				lock_room(t_data *data, int found);
void				lock_rooms(t_data *data, int *s);
void				zero_links(t_data *data);
int					check_ways(t_data *data, t_route **route);
int					find_smallest(t_data *data);
int					only_digits(char *s);
void				mark_links(t_data *data, t_room *cur1, t_room *cur2);
int					handle_comments(t_data *data);
int					save_str(t_data *data);

t_queue				*init_queue(int index, int i);
int					add_queue(t_queue **queue, int index, int i);
void				free_cur_queue(t_queue **queue);
int					check_queue(t_queue *queue, int index);
int					find_next_ant(t_data *data, int ant_name);
int					find_in_finish(t_data *data, int ant_name);

void				let_ants_out(t_data *data);
void				print_map(t_data *data);
void				print_routes(t_data *data);

void				free_mass(char **mass);
void				free_route(t_data *data);
void				free_rooms(t_data *data);
void				free_data(t_data *data);
void				free_links(t_data *data);
void				free_map(t_data *data);

#endif
