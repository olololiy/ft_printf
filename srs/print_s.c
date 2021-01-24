//
// Created by Violet Furr on 1/24/21.
//
#include "../includes/lib_printf.h"
void print_str(/*const char *str, */struct t_flags *flags, va_list args)                // print str
{
//    int j = 0;
	char *t_str = va_arg(args, char *);
	int len_str = ft_strlen(t_str);
	if (len_str > flags->dot && flags->dot != -1)
		len_str = flags->dot;


	if(flags->minus == 1)
	{
		write(1, t_str, len_str);
		while((flags->width-len_str) > 1)
		{
			write(1," ",1);
			flags->width--;
		}
	}
	else
	{
		while(flags->width-len_str > 1)
		{
			write(1," ",1);
			flags->width--;
		}
		write(1, t_str, len_str);                                   // сюда же можно воткнуть флаг 0
	}

}