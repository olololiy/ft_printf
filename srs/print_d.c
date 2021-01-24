//
// Created by Violet Furr on 1/24/21.
//
#include "../includes/lib_printf.h"
void print_d(/*const char *str, */struct t_flags *flags, va_list args)              //pprint d
{
	//int j = 0;
	int d = va_arg(args, int );
	char *str_d = ft_itoa(d);
	int len_d = ft_strlen(str_d);

	if (d == 0 && flags->dot == 0)
		return;
	else if (!flags->minus && !flags->zero)                                          // without flags
	{
		while (flags->width > len_d && (flags->width > flags->dot)) {
			flags->width--;
			write(1, " ", 1);
			flags->result++;
		}
		while(flags->dot > len_d)
		{
			flags->dot--;
			write(1, "0", 1);
			flags->result++;
		}
		write(1, str_d, len_d);
		flags->result = flags->result +len_d;
	}
	else if (flags->minus && !flags->zero)                                               // minus
	{
		while(flags->dot > len_d)
		{
			flags->dot--;
			flags->width--;
			write(1, "0", 1);
			flags->result++;
		}
		write(1, str_d, len_d);
		flags->result = flags->result +len_d;
		while (flags->width > len_d && (flags->width > flags->dot)) {
			flags->width--;
			write(1, " ", 1);
			flags->result++;
		}
	}
	else if (!flags->minus && flags->zero)                              // zero
	{
		while (flags->dot == -1 && flags->width>len_d)
		{
			flags->width--;
			write(1, "0", 1);
			flags->result++;
		}
		while (flags->dot < flags->width)
		{
			flags->width--;
			write(1, " ", 1);
			flags->result++;
		}
		while (flags->dot > len_d)
		{
			flags->dot--;
			write(1, "0", 1);
			flags->result++;
		}
		write(1, str_d, len_d);
		flags->result = flags->result +len_d;
	}
	else
		write(1, " ", 1);

}