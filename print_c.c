/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:39:51 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/30 22:40:10 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_c(t_flags *flags, va_list args)                   // print_c
{
	char a = va_arg(args, int);
	if(flags->minus == 1)
	{
		write(1, &a, 1);
		flags->result++;
		while(flags->width > 1)
		{
			write(1," ",1);
			flags->width--;
			flags->result++;
		}
	}
	else
	{
		while(flags->width > 1)
		{
			write(1," ",1);
			flags->width--;
			flags->result++;
		}
		write(1, &a, 1);
		flags->result++;
	}
}
