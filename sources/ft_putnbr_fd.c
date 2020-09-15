/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:22:17 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:22:33 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long nbr_l;

	nbr_l = n;
	if (nbr_l < 0)
	{
		ft_putchar_fd('-', fd);
		if (-nbr_l > 9)
			ft_putnbr_fd((nbr_l / 10) * -1, fd);
		ft_putnbr_fd(-1 * (nbr_l % 10), fd);
	}
	else if (nbr_l > 9)
	{
		ft_putnbr_fd(nbr_l / 10, fd);
		ft_putchar_fd(nbr_l % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr_l + '0', fd);
}
