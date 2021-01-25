/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:11:12 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/16 00:11:15 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/lib_printf.h"

int g_result;
//int flags->i;

t_flags		ft_init_flags(void)
{
    t_flags		flags;

    flags.dot = -1;
    flags.minus = 0;
    flags.star = 0;
    flags.type = 0;
    flags.width = -1;
    flags.zero = 0;
    flags.result = 0;
	flags.i = 0;
    return (flags);
}

void ft_flag_widht(const char *str, struct t_flags *flags, va_list args)           // width
{
    flags->width = 0;
    if (str[flags->i] == '*') {
        flags->width = va_arg(args, int);
        flags->i++;
    }
    else {
        while (ft_isdigit(str[flags->i])) {
            flags->width = (flags->width * 10) + (str[flags->i] - '0');
            flags->i++;
        }
    }
}

void ft_flag_dot(const char *str, struct t_flags *flags, va_list args)               //dot
{
    flags->dot = 0;
    if (str[flags->i] == '*')
    {
        flags->dot = va_arg(args, int);
        flags->i++;
    }
    else if (ft_isdigit(str[flags->i]))
    {
        flags->dot = 0;//del
        while (ft_isdigit(str[flags->i]))
            flags->dot = (flags->dot * 10) + (str[flags->i++] - '0');
    }
}

void ft_flag_type(const char *str, struct t_flags *flags)                           // type
{
    flags->type = str[flags->i];
    flags->i++;
}

void print_type(/*const char *str, */struct t_flags *flags, va_list args)               //print type
{
    if (flags->type == 'c')
    {
        print_c(/*str, */flags, args);
    }
    else if (flags->type == 's')
    {
        print_str(/*str, */flags, args);
    }
    else if (flags->type == 'd' || flags->type == 'i')
    {
        print_d(/*str, */flags, args);
    }
}

void obrabot_ochka(const char *str, struct t_flags *flags, va_list args)//parser
{
    while(str[flags->i] == '0' && str[flags->i] == '0')     //flag - 0
    {
        flags->zero = 1;//zakin flag
        flags->i++;
    }
    if(str[flags->i] == '-')
    {
        flags->minus = 1;
        flags->i++;
    }
    if(str[flags->i] == '*' || (str[flags->i] >= '0' && str[flags->i]<= '9'))     // width
    {
        ft_flag_widht(str, flags, args);
    }
    if(str[flags->i] == '.')          // dot
    {
        flags->i++;
        	ft_flag_dot(str, flags, args);
    }
    ft_flag_type(str, flags);
}


int ft_printf(const char *str, ... )
{
    va_list		args;
    t_flags		flags;
	flags = ft_init_flags();
    va_start(args, str);
    while (str[flags.i] != '\0')
    {
        if (str[flags.i] != '%') {
            ft_putchar(str[flags.i]);
            flags.i++;
            flags.result++;
        }
        else if(str[flags.i] == '%') {
            flags.i++;
            //flags = ft_init_flags();
            obrabot_ochka(str, &flags, args);
            print_type(/*str, */&flags, args);
        }
    }
    return (flags.result);
}
/*
int main()
{
    char *a_str = "huy";
    char b = 'r';
    int a = 300;
   // printf("%  - 10.15d", a);
    ft_printf("her%010.6dah", a);
}*/