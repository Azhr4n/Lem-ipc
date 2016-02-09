/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:07:17 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/07 16:07:17 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

#include "defines.h"
#include "structs.h"
#include "src.h"

void		moving_x(t_player *player, int dir)
{
	player->map[player->posy][player->posx] = 0;
	player->map[player->posy][player->posx + dir] = player->team;
	player->posx += dir;
}

void		moving_y(t_player *player, int dir)
{
	player->map[player->posy][player->posx] = 0;
	player->map[player->posy + dir][player->posx] = player->team;
	player->posy += dir;
}

int			check_and_move(t_player *player, int random)
{
	if (random == LEFT && !check_left(player))
	{
		moving_x(player, -1);
		return (1);
	}
	else if (random == RIGHT && !check_right(player))
	{
		moving_x(player, 1);
		return (1);
	}
	else if (random == UP && !check_up(player))
	{
		moving_y(player, -1);
		return (1);
	}
	else if (random == DOWN && !check_down(player))
	{
		moving_y(player, 1);
		return (1);
	}
	return (0);
}

void		moving_loop(t_player *player)
{
	int		quit;
	time_t	timer;
	time_t	start;

	quit = 0;
	timer = 0;
	start = time(0);
	while (!quit)
	{
		if (time(0) != timer)
		{
			print_map(player);
			printf("\n");
			timer = time(0);
			if (!quit)
			{
				sem_lock(player);
				moving(player);
				sem_unlock(player);
			}
		}
		if (am_i_circle(player) || time(0) - start == TIMEOUT)
			quit = 1;
	}
}

void		moving(t_player *player)
{
	int		timeout;
	int		random;
	int		done;
	int		ret;
	int		fd;

	done = 0;
	timeout = 0;
	fd = open("/dev/random", O_RDONLY);
	while (!done)
	{
		ret = read(fd, &random, sizeof(int));
		random = ABS(random) % 4;
		if (check_and_move(player, random) || !ret || timeout == 5000)
			done = 1;
		timeout++;
	}
	close(fd);
}
