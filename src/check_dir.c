/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:09:52 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/07 16:09:53 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "structs.h"
#include "src.h"

int			check_up(t_player *player)
{
	if (player->posy > 0)
	{
		if (player->map[player->posy - 1][player->posx] != 0)
			return (1);
		return (0);
	}
	return (1);
}

int			check_down(t_player *player)
{
	if (player->posy < HEIGHT - 1)
	{
		if (player->map[player->posy + 1][player->posx] != 0)
			return (1);
		return (0);
	}
	return (1);
}

int			check_left(t_player *player)
{
	if (player->posx > 0)
	{
		if (player->map[player->posy][player->posx - 1] != 0)
			return (1);
		return (0);
	}
	return (1);
}

int			check_right(t_player *player)
{
	if (player->posx < WIDTH - 1)
	{
		if (player->map[player->posy][player->posx + 1] != 0)
			return (1);
		return (0);
	}
	return (1);
}
