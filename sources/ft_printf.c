/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:17:43 by acyrenna          #+#    #+#             */
/*   Updated: 2021/02/13 15:17:44 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		arg_free(t_argument *arg)
{
	ft_strdel(&(arg->special));
	ft_strdel(&(arg->data));
	ft_strdel(&(arg->modificator));
	ft_memdel((void **)&arg);
}

static size_t	define_arg(int fd, va_list *args, t_argument *arg)
{
	if (arg->type >= F && arg->type <= U)
		handle_number(arg, args);
	else if (arg->type == C || arg->type == S)
		handle_chars(arg, args);
	else if (arg->type == P)
		handle_pointer(arg, args);
	return (arg_print(fd, arg));
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_argument	*arg;
	size_t		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
		if (*format == '%' && (arg = arg_parse(format)))
		{
			printed += define_arg(fd, &args, arg);
			format += arg->size;
			arg_free(arg);
		}
		else
			format += handle_invalid(fd, format, &printed);
	va_end(args);
	return (printed);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_argument	*arg;
	size_t		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
		if (*format == '%' && (arg = arg_parse(format)))
		{
			printed += define_arg(1, &args, arg);
			format += arg->size;
			arg_free(arg);
		}
		else
			format += handle_invalid(1, format, &printed);
	va_end(args);
	return (printed);
}
