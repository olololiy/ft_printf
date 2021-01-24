//
// Created by Violet Furr on 1/24/21.
//
#include "../includes/lib_printf.h"

void print_c(/*const char *str, */struct t_flags *flags, va_list args)                   // print_c
{
	char a = va_arg(args, int);
	if(flags->minus == 1)
	{
		write(1, &a, 1);
		while(flags->width > 1)
		{
			write(1," ",1);
			flags->width--;
		}
	}
	else
	{
		while(flags->width > 1)
		{
			write(1," ",1);
			flags->width--;
		}
		write(1, &a, 1);
	}
}
