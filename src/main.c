/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:50:11 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/05 16:50:11 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "defines.h"
#include "structs.h"
#include "tools.h"
#include "src.h"

void		detach_and_clean(t_player *player, int supr)
{
	union semun		arg;

	player->map[player->posy][player->posx] = 0;
	if (shmdt(player->shm.addr) == -1)
		ft_putstr("Shmdt failed.\n", 2);
	ft_putstr("Detaching from shared memory.\n", 1);
	if (supr)
	{
		if (semctl(player->sem.id, 0, IPC_RMID, arg) == -1)
			ft_putstr("Semctl failed.\n", 2);
		ft_putstr("Semaphore deleted.\n", 1);
		if (shmctl(player->shm.id, IPC_RMID, 0) == -1)
			ft_putstr("Shmctl failed.\n", 2);
		ft_putstr("Shared memory deleted.\n", 1);
	}
}

void		init_sem(t_player *player)
{
	union semun		arg;

	arg.val = 1;
	player->sem.key = ftok("main.c", 'A');
	player->sem.id = semget(player->sem.key, NSEM, 0644 | IPC_CREAT);
	if (semctl(player->sem.id, 0, SETVAL, arg) == -1)
	{
		ft_putstr("Semctl failed.\2", 2);
		exit(-1);
	}
}

void		create_shm(t_player *player)
{
	ft_putstr("Creating shared memory.\n", 1);
	if ((player->shm.id = shmget(player->shm.key
		, WIDTH * HEIGHT + HEIGHT, 0644 | IPC_CREAT)) == -1)
	{
		ft_putstr("Shmget failed.\n", 2);
		exit(-1);
	}
	ft_putstr("Initialisation of semaphore.\n", 1);
	init_sem(player);
	if ((player->shm.addr = (char *)shmat(player->shm.id
		, (void *)0, 0)) == (char *)(-1))
	{
		ft_putstr("Shmat failed.\n", 2);
		if (shmctl(player->shm.id, IPC_RMID, 0) == -1)
			ft_putstr("Shmctl failed.\n", 2);
		ft_putstr("Memory shared deleted.\n", 2);
		exit(-1);
	}
	setting_map(player);
}

void		running_game(t_player *player, char *str)
{
	player->sem.key = ftok("main.c", 'A');
	player->sem.id = semget(player->sem.key, NSEM, 0644);
	player->sb.sem_num = 0;
	player->sb.sem_flg = SEM_UNDO;
	sem_lock(player);
	spawn(player, str_to_int(str));
	sem_unlock(player);
	moving_loop(player);
	print_map(player);
	if (am_i_alone(player))
		detach_and_clean(player, 1);
	else
		detach_and_clean(player, 0);
}

int			main(int ac, char **av)
{
	t_player	player;

	if (ac == 2)
	{
		(void)av;
		player.shm.key = ftok("main.c", 'a');
		if ((PSI = shmget(player.shm.key, WIDTH * HEIGHT + HEIGHT, 0644)) == -1)
			create_shm(&player);
		else
		{
			ft_putstr("Joining shared memory.\n", 1);
			if ((PSA = (char *)shmat(player.shm.id, (void *)0, 0)) == CMUN)
			{
				ft_putstr("Shmat failed.\n", 2);
				if (shmctl(player.shm.id, IPC_RMID, 0) == -1)
					ft_putstr("Shmctl failed.\n", 2);
				exit(-1);
			}
			get_map_from_shm(&player);
		}
		running_game(&player, av[1]);
	}
	else if (ac == 1)
		ft_putstr("You have to enter a team number !\n", 1);
	return (0);
}
