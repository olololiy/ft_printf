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

int		ft_isdigit(int c)                                           //isdigit
{
    int b;

    if (c >= '0' && c <= '9')
        b = 1;
    else
        b = 0;
    return (b);
}


static void ft_putchar(char c)                                       //ft_putchar
{
    write(1, &c, 1);
    g_result += 1;
}
int	ft_strlen( char *str)
{
    int j;

    j = 0;
    while (*str)
    {
        str++;
        j++;
    }
    return (j);
}


void ft_flag_widht(const char *str, struct t_flags *flags, va_list args)           // width
{
    if (str[i] == '*') {
        flags->width = va_arg(args, int);
        i++;
    }
    else
        while(ft_isdigit(str[i]))
            flags->width = (flags->dot * 10) + (str[i++] - '0');

}

void ft_flag_dot(const char *str, struct t_flags *flags, va_list args)               //dot
{
    if (str[i] == '*')
    {
        flags->dot = va_arg(args, int);
        i++;
    }
    else {
        flags->dot = 0;
        while (ft_isdigit(str[i]))
            flags->dot = (flags->dot * 10) + (str[i++] - '0');
    }
}

void ft_flag_type(const char *str, struct t_flags *flags)                           // type
{
    flags->type = str[i];
    i++;
}
void print_c(const char *str, struct t_flags *flags, va_list args)                   // print_c
{
    char a = va_arg(args, int);
    if(flags->minus == 1)
    {
        write(1, &a, 1);
        while(flags->width != 1)
        {
            write(1," ",1);
            flags->width--;
        }
    }
    else
    {
        while(flags->width != 1)
        {
            write(1," ",1);
            flags->width--;
        }
        write(1, &a, 1);
    }
}

void print_str(const char *str, struct t_flags *flags, va_list args)                // print str
{
    int j = 0;
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
        write(1, t_str, len_str);
    }

}

void print_type(const char *str, struct t_flags *flags, va_list args)               //print type
{
    if (flags->type == 'c')
    {
        print_c(str, flags, args);
    }
    if (flags->type == 's')
    {
        print_str(str, flags, args);
    }

}

void obrabot_ochka(const char *str, struct t_flags *flags, va_list args)//parser
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
        ft_flag_widht(str, flags, args);
    }
    if(str[i] == '.')          // dot
    {
        i++;
        ft_flag_dot(str, flags, args);
    }
    ft_flag_type(str, flags);
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
            obrabot_ochka(str, &flags, args);
            print_type(str, &flags, args);
        }
    }
    return 0;
}

int main()
{
    char *a_str = "huy";
    char b = ' ';
    int a = 3;
   // printf("%  - 10.1d", a);
    ft_printf("her%-20.1sah", a_str);
}