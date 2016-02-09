/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:10:38 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/07 16:10:39 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "structs.h"
#include "src.h"

int			check_up_p(t_player *player)
{
	if (player->posy > 0)
	{
		if (player->map[player->posy - 1][player->posx] == player->team)
			return (0);
		return (1);
	}
	return (0);
}

int			check_down_p(t_player *player)
{
	if (player->posy < HEIGHT - 1)
	{
		if (player->map[player->posy + 1][player->posx] == player->team)
			return (0);
		return (1);
	}
	return (0);
}

int			check_left_p(t_player *player)
{
	if (player->posx > 0)
	{
		if (player->map[player->posy][player->posx - 1] == player->team)
			return (0);
		return (1);
	}
	return (0);
}

int			check_right_p(t_player *player)
{
	if (player->posx < WIDTH - 1)
	{
		if (player->map[player->posy][player->posx + 1] == player->team)
			return (0);
		return (1);
	}
	return (0);
}
