/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:11:49 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/07 16:11:50 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "defines.h"
#include "structs.h"
#include "src.h"

int			am_i_circle(t_player *player)
{
	int		nb;

	nb = 0;
	if (check_left(player) && check_left_p(player))
		nb++;
	if (check_right(player) && check_right_p(player))
		nb++;
	if (check_up(player) && check_up_p(player))
		nb++;
	if (check_down(player) && check_down_p(player))
		nb++;
	if (nb >= 2)
		return (1);
	return (0);
}

int			am_i_alone(t_player *player)
{
	int		i;
	int		j;

	sem_lock(player);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if ((i != player->posy
				|| j != player->posx) && player->map[i][j] != 0)
			{
				sem_unlock(player);
				return (0);
			}
			j++;
		}
		i++;
	}
	sem_unlock(player);
	return (1);
}

void		spawn(t_player *player, int team_flag)
{
	int		fd;
	int		posx;
	int		posy;
	int		done;
	int		random;

	fd = open("/dev/random", O_RDONLY);
	done = 0;
	while (!done)
	{
		read(fd, &random, sizeof(int));
		random = ABS(random) % (WIDTH * HEIGHT);
		posx = random % WIDTH;
		posy = random / HEIGHT;
		if (player->map[posy][posx] == 0)
		{
			player->map[posy][posx] = team_flag;
			player->team = team_flag;
			player->posx = posx;
			player->posy = posy;
			done = 1;
		}
	}
	close(fd);
}
