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
#include "lib_ft_printf.h"
//#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <zconf.h>

int g_result;
int i;

t_flags		ft_init_flags(void)
{
    t_flags		flags;

    flags.dot = -1;
    flags.minus = 0;
    flags.star = 0;
    flags.type = 0;
    flags.width = 0;
    flags.zero = 0;
    flags.result = 0;
    return (flags);
}

int		ft_isdigit(int c)
{
    int b;

    if (c >= '0' && c <= '9')
        b = 1;
    else
        b = 0;
    return (b);
}


static void ft_putchar(char c)
{
    write(1, &c, 1);
    g_result += 1;
}

void ft_flag_widht(char *str, va_list args, t_flags *flags)
{
    if (str[i] == '*') {
        flags->width = va_arg(args, int);
        i++;
    }
    else
        while(ft_isdigit(str[i]))
            flags->width = (flags->dot * 10) + (str[i++] - '0');

}

void ft_flag_dot(char *str, va_list args, t_flags *flags)
{
    if (str[i] == '*') {
        flags->dot = va_arg(args, int);
        i++;
    }
    else {
        flags->dot = 0;
        while (ft_isdigit(str[i]))
            flags->dot = (flags->dot * 10) + (str[i++] - '0');
    }
}

void ft_flag_type(char *str, va_list args, t_flags *flags)
{
    flags->type = str[i];
    i++;
}
void print_c(char *str, va_list args, t_flags *flags)
{
    if(flags->width == 0 || flags->minus == 1)
    {
        write(1,va_arg(args, char ), 1);
    }
    else
    {
        if
    }
}
void print_type(char *str, va_list args, t_flags *flags)
{
    if (flags->type == 'c')
    {
        print_c(str, args, flags);
    }
}

void obrabot_ochka(char *str, t_flags *flags, va_list args)//parser
{

    if(str[i] == '0')     //flag - 0
    {
        flags->zero = 1;//zakin flag
        i++;

    }
    if(str[i] == '-')
    {
        flags->minus = 1;
        i++;
    }
    if(str[i] == '*' || (str[i] >= '0' && str[i]<= '9'))     // width
    {
        ft_flag_widht(str, args, flags);
    }
    if(str[i] == '.')          // dot
    {
        i++;
        ft_flag_dot(str, args, flags);
    }
    ft_flag_type(str, args, flags);
}


int ft_printf(const char *str, ... )
{
  //  int c_count = 0;
    va_list		args;
    t_flags		flags;
    char *t_str =(char *)str;


    va_start(args, str);
    while (str[i] != '\0')
    {
        if (str[i] != '%') {
            ft_putchar(str[i]);
            i++;
        }
        else if(str[i] == '%') {
            i++;
            flags = ft_init_flags();
            obrabot_ochka(t_str, &flags, args);
            //print_type(&flags, args);
        }
    }
    return 0;
}

int main()
{
    char *str = "huy";
    int a = 3;
   // printf("%  - 10.1d", a);
    ft_printf("her%-*.*cah", 2, 5);
}