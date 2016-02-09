/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:08:46 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/07 16:08:47 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

void		detach_and_clean(t_player *player, int supr);
void		running_game(t_player *player, char *str);
void		spawn(t_player *player, int team_flag);
void		moving_x(t_player *player, int dir);
void		moving_y(t_player *player, int dir);
void		get_map_from_shm(t_player *player);
void		moving_loop(t_player *player);
void		setting_map(t_player *player);
void		sem_unlock(t_player *player);
void		create_shm(t_player *player);
void		print_map(t_player *player);
void		init_sem(t_player *player);
void		sem_lock(t_player *player);
void		moving(t_player *player);

int			check_and_move(t_player *player, int random);
int			check_right_p(t_player *player);
int			check_down_p(t_player *player);
int			check_left_p(t_player *player);
int			am_i_circle(t_player *player);
int			check_right(t_player *player);
int			am_i_alone(t_player *player);
int			check_up_p(t_player *player);
int			check_down(t_player *player);
int			check_left(t_player *player);
int			check_up(t_player *player);

#endif
