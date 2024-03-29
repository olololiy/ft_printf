/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:11:12 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/31 13:47:56 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.type = 0;
	flags.width = -1;
	flags.zero = 0;
	flags.result = 0;
	flags.i = 0;
	flags.space = 0;
	return (flags);
}

void		all_zero_flags(t_flags *flags)
{
	flags->dot = -1;
	flags->minus = 0;
	flags->type = 0;
	flags->width = -1;
	flags->zero = 0;
	flags->space = 0;
}

void		print_type(t_flags *flags, va_list args)
{
	if (flags->type == 'c')
		print_c(flags, args);
	else if (flags->type == 's')
		print_str(flags, args);
	else if (flags->type == 'u')
		print_u(flags, args);
	else if (flags->type == 'd' || flags->type == 'i')
		print_dd(flags, args);
	else if (flags->type == 'x' || flags->type == 'X')
		print_xx(flags, args);
	else if (flags->type == 'p')
		print_p(flags, args);
	else if (flags->type == '%')
		print_prec(flags);
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_flags		flags;

	flags = ft_init_flags();
	va_start(args, str);
	while (str[flags.i] != '\0')
	{
		if (str[flags.i] != '%')
		{
			ft_putchar(str[flags.i]);
			flags.i++;
			flags.result++;
		}
		else if (str[flags.i] == '%')
		{
			flags.i++;
			all_zero_flags(&flags);
			obrabot_ochka(str, &flags, args);
			print_type(&flags, args);
		}
	}
	va_end(args);
	return (flags.result);
}
