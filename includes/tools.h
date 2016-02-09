/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:20:17 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/05 18:20:17 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void		ft_putchar(char c, int fd);
void		ft_putstr(char *str, int fd);
void		free_2d(void **tab, int nb_c);

int			str_to_int(char *str);

#endif
