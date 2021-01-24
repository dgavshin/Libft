/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:12:41 by acyrenna          #+#    #+#             */
/*   Updated: 2020/05/13 12:37:31 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_right(int fd, t_argument *arg, size_t *printed, char
																	*field)
{
	if (arg->field_filling == ' ' && field)
		*printed += cputstr(fd, field);
	if (arg->sign_display)
		*printed += cputchar(fd, arg->sign_display);
	if (arg->special && arg->afterpoint >= 0)
		*printed += cputstr(fd, arg->special);
	else if (arg->type == O && arg->special)
		*printed += cputstr(fd, arg->special);
	if (arg->field_filling == '0' && field)
		*printed += cputstr(fd, field);
	if ((arg->afterpoint >= 0 || arg->type == F) || !ft_strequ(arg->data, "0"))
		*printed += cputstr(fd, arg->data);
	if (arg->type == C && arg->data[0] == '\0')
		*printed += cputchar(fd, 0);
	ft_strdel(&field);
}

static void		handle_left(int fd, t_argument *arg, size_t *printed, char
*field)
{
	if (arg->afterpoint >= 0 || arg->field_size > 0)
	{
		if (arg->sign_display)
			*printed += cputchar(fd, arg->sign_display);
		if (arg->special)
			*printed += cputstr(fd, arg->special);
		*printed += cputstr(fd, arg->data);
		if (arg->type == C && arg->data[0] == '\0')
			*printed += cputchar(fd, 0);
	}
	else if (arg->type == O && arg->special)
		*printed += cputstr(fd, arg->special);
	if (field)
		*printed += cputstr(fd, field);
	ft_strdel(&field);
}

static int		define_precision(t_argument *arg)
{
	int		precision;
	int		data_len;
	char	*data;

	if (ft_strequ(arg->data, "0") && arg->afterpoint != 0 && arg->type != F)
		arg->data[0] = '\0';
	data_len = ft_strlen(arg->data);
	precision = arg->afterpoint - data_len - (arg->type == O ? \
											ft_strlen(arg->special) : 0);
	if ((arg->type > F && arg->type <= U) || arg->type == P)
	{
		if (precision > 0)
		{
			data = ft_memalloc(precision + data_len + 1);
			ft_memset(data, '0', precision + data_len);
			ft_memmove(data + precision, arg->data, data_len);
			ft_strdel(&(arg->data));
			arg->data = data;
			arg->field_filling = ' ';
			return (precision);
		}
		else if (arg->afterpoint > 0)
			arg->field_filling = ' ';
	}
	return (0);
}

size_t			arg_print(int fd, t_argument *arg)
{
	int		fillsize;
	char	*field;
	size_t	printed;

	printed = 0;
	field = 0;
	define_precision(arg);
	fillsize = arg->field_size - ft_strlen(arg->data) - ft_strlen(arg->special)\
	- (arg->sign_display ? 1 : 0) - (arg->type == C && !(*arg->data) ? 1 : 0);
	if (fillsize > 0)
		field = ft_memset(ft_memalloc(fillsize + 1), arg->field_filling, \
																	fillsize);
	if (arg->alignment == RIGHT)
		handle_right(fd, arg, &printed, field);
	else
		handle_left(fd, arg, &printed, field);
	return (printed);
}
