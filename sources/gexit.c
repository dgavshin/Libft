/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:20:24 by acyrenna          #+#    #+#             */
/*   Updated: 2021/02/13 15:20:26 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gexit(char *format, char *f1, char *f2, char *f3)
{
	ft_putstr_fd("\033[1;3;31m", 2);
	ft_putstr_fd("Error: ", 2);
	ft_dprintf(2, format, f1, f2, f3);
	ft_putendl_fd("\033[0m", 2);
	exit(0);
}
