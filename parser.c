/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:11:12 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/16 00:11:15 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib_printf.h"

void ft_flag_widht(const char *str, struct t_flags *flags, va_list args)
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
	{
		if((str[flags->i]) == '-')
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

void ft_flag_dot(const char *str, struct t_flags *flags, va_list args)
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

void ft_flag_type(const char *str, struct t_flags *flags)
{
	flags->type = str[flags->i];
	flags->i++;
}
void obrabot_ochka(const char *str, struct t_flags *flags, va_list args)
{
	while (str[flags->i] == ' ')
		flags->i++;
	if (str[flags->i - 1] == ' ') {
		write(1, " ", 1);
		flags->result++;
	}
	if (str[flags->i] == '%')
	{
		flags->type = '%';
		flags->result++;
		flags->i++;
		return;
	}
	while (str[flags->i] == '0')
	{
		flags->zero = 1;
		flags->i++;
	}
	while (str[flags->i] == '-')
	{
		flags->minus = 1;
		flags->i++;
		flags->zero = 0;
	}
	if (str[flags->i] == '*' || (str[flags->i] >= '0' && str[flags->i]<= '9'))
		ft_flag_widht(str, flags, args);
	if (str[flags->i] == '.')
		ft_flag_dot(str, flags, args);
	if (str[flags->i])
		ft_flag_type(str, flags);
}