/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:41:18 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/27 19:51:08 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lib_printf.h"

static void	without_d(int d, char *str_d, int len_d, struct t_flags *flags)
{
	int y;

	if (d < 0 && flags->dot >= len_d)
		flags->width--;
	y = flags->width - flags->dot;
	while (flags->width > len_d && /*(flags->width > flags->dot)*/ y-- > 0 )
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
	if (d < 0)
	{
		write(1, "-", 1);
		flags->result++;
		str_d++;
		len_d--;
	}
	while (flags->dot > len_d)
	{
		flags->dot--;
		write(1, "0", 1);
		flags->result++;
	}
	write(1, str_d, len_d);
	flags->result = flags->result + len_d;
}

static void	zero_d(int d, char *str_d, int len_d, struct t_flags *flags)
{
	if (d < 0 && flags->dot > len_d - 1)
		flags->dot++;
	while (flags->dot < flags->width && flags->width > len_d && flags->dot > -1)
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
	if (d < 0)
	{
		write(1, "-", 1);
		flags->result++;
		str_d++;
	}
	while (flags->dot > len_d || flags->width > len_d)
	{
		flags->dot--;
		write(1, "0", 1);
		flags->result++;
		flags->width--;
	}
	if (d < 0)
		len_d--;
	write(1, str_d, len_d);
	flags->result = flags->result + len_d;
}

static void	minus_d(int d, char *str_d, int len_d, struct t_flags *flags)
{
	if (d < 0)
	{
		write(1, "-", 1);
		flags->result++;
		str_d++;
		len_d--;
		flags->width--;
	}
	while (flags->dot > len_d)
	{
		flags->dot--;
		flags->width--;
		write(1, "0", 1);
		flags->result++;
	}
	write(1, str_d, len_d);
	flags->result = flags->result + len_d;
	while (flags->width > len_d && (flags->width > flags->dot))
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
}

void	print_dd(struct t_flags *flags, va_list args)
{
	int	d;
	char	*str_d;
	int		len_d;

	d = va_arg(args, int);
	str_d = ft_itoa(d);
	len_d = ft_strlen(str_d);
	if (d == 0 && flags->dot == 0)
	{
		while (flags->width-- > 0)
		{
			write(1, " ", 1);
			flags->result++;
		}
	}
	else if (!flags->minus && !flags->zero)
		without_d(d, str_d, len_d, flags);
	else if (!flags->minus && flags->zero)
		zero_d(d, str_d, len_d, flags);
	else if (flags->minus && !flags->zero)
		minus_d(d, str_d, len_d, flags);
	free(str_d);
}