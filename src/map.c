/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:12:32 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/07 16:12:33 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "defines.h"
#include "structs.h"
#include "src.h"

void		print_map(t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			printf("| %d ", player->map[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
}

void		setting_map(t_player *player)
{
	int		i;
	int		j;

	player->map = (int **)malloc(sizeof(int *) * (HEIGHT));
	i = 0;
	while (i < HEIGHT)
	{
		player->map[i] = (int *)player->shm.addr + (i * WIDTH);
		j = 0;
		while (j < WIDTH)
		{
			player->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		get_map_from_shm(t_player *player)
{
	int		i;

	player->map = (int **)malloc(sizeof(int *) * (HEIGHT));
	i = 0;
	while (i < HEIGHT)
	{
		player->map[i] = (int *)player->shm.addr + (i * WIDTH);
		i++;
	}
}
