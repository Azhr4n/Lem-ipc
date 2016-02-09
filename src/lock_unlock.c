/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:38:56 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/09 17:38:56 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <stdlib.h>

#include "structs.h"
#include "tools.h"
#include "src.h"

void		sem_lock(t_player *player)
{
	player->sb.sem_op = -1;
	if (semop(player->sem.id, &player->sb, 1) == -1)
	{
		ft_putstr("Semop failed.\n", 2);
		exit(-1);
	}
}

void		sem_unlock(t_player *player)
{
	player->sb.sem_op = 1;
	if (semop(player->sem.id, &player->sb, 1) == -1)
	{
		ft_putstr("Semop failed.\n", 2);
		exit(-1);
	}
}
