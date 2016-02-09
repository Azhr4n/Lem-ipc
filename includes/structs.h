/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:51:33 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/06 16:51:33 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/shm.h>
# include <sys/sem.h>

typedef struct sembuf	t_sembuf;

typedef struct			s_mem
{
	key_t				key;
	char				*addr;
	int					id;
}						t_mem;

typedef struct			s_sem
{
	int					id;
	key_t				key;
}						t_sem;

typedef struct			s_player
{
	int					team;
	int					**map;
	int					posx;
	int					posy;
	t_mem				shm;
	t_sem				sem;
	t_sembuf			sb;
}						t_player;

#endif
