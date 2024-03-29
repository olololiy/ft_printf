/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:11:12 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/31 17:17:54 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_widht_else(const char *str, t_flags *flags)
{
	{
		if ((str[flags->i]) == '-')
		{
			flags->i++;
			flags->minus = 1;
			flags->zero = 0;
		}
		while (ft_isdigit(str[flags->i]))
		{
			flags->width = (flags->width * 10) + (str[flags->i] - '0');
			flags->i++;
		}
	}
}

void	ft_flag_widht(const char *str, t_flags *flags, va_list args)
{
	flags->width = 0;
	if (str[flags->i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width = flags->width * -1;
		}
		flags->i++;
	}
	else
		ft_flag_widht_else(str, flags);
}

void	ft_flag_dot(const char *str, t_flags *flags, va_list args)
{
	flags->i++;
	flags->dot = 0;
	if (str[flags->i] == '*')
	{
		flags->dot = va_arg(args, int);
		flags->i++;
	}
	else if (ft_isdigit(str[flags->i]))
	{
		flags->dot = 0;
		while (ft_isdigit(str[flags->i]))
			flags->dot = (flags->dot * 10) + (str[flags->i++] - '0');
	}
}

void	ft_flag_type(const char *str, t_flags *flags)
{
	flags->type = str[flags->i];
	flags->i++;
}

int		obrabot_ochka(const char *str, t_flags *flags, va_list args)
{
	while (str[flags->i] == ' ' || str[flags->i] == '0' || str[flags->i] == '-')
	{
		if (str[flags->i] == ' ')
			flags->space = 1;
		if (str[flags->i] == '%')
			return (flags->type = '%');
		if (str[flags->i] == '0')
			flags->zero = 1;
		if (str[flags->i++] == '-')
			flags->minus = 1;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	if (str[flags->i] == '*' || (str[flags->i] >= '0' && str[flags->i] <= '9'))
		ft_flag_widht(str, flags, args);
	if (str[flags->i] == '.')
		ft_flag_dot(str, flags, args);
	if (str[flags->i])
		ft_flag_type(str, flags);
	return (0);
}
