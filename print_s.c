/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:41:22 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/30 22:41:36 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void print_str(t_flags *flags, va_list args)                // print str
{
	char *t_str;
	int len_str;
	if (!(t_str = va_arg(args, char *)))
	{
		t_str = "(null)";
		if ((flags->dot < 0 || flags->dot > 6))
			flags->dot = 6;
	}
	len_str = ft_strlen(t_str);

	if (len_str > flags->dot && flags->dot >= 0)
		len_str = flags->dot;
	if ((flags->dot < 0 && flags->dot > len_str))	// я не помню нахер я это поставил
		flags->dot = len_str;
	if(flags->minus == 1)
	{
		write(1, t_str, len_str);
		flags->result = flags->result + len_str;
		while((flags->width-len_str) > 0)
		{
			write(1," ",1);
			flags->width--;
			flags->result++;
		}
	}
	else
	{
		while(flags->width-len_str > 0)
		{
			write(1," ",1);
			flags->width--;
			flags->result++;
		}
		write(1, t_str, len_str);                                   // сюда же можно воткнуть флаг 0
		flags->result = flags->result + len_str;
	}

}
