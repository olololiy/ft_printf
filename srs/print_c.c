//
// Created by Violet Furr on 1/24/21.
//
#include "../includes/lib_printf.h"

void print_c(struct t_flags *flags, va_list args)                   // print_c
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
