/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:21:21 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/29 20:14:55 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cputchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int		cputstr(int fd, const char *str)
{
	if (!str)
		return (0);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
