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
#include <stdio.h>
#include <unistd.h>
#include <zconf.h>

/*int g_result;
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
    return (flags);
}



static void ft_putchar(char c)
{
    write(1, &c, 1);
    g_result += 1;
}

int obrabot_ochka(char *str, va_list args)
{

}

int ft_printf(const char *str, ... )
{
    //int i = 0;
    va_list		args;

    va_start(args, str);
    while (str[i] != '\0')
    {
        if (str[i] != '%') {
            ft_putchar(str[i]);
            i++;
        }
        else if(str[i] == '%')
            obrabot_ochka(str, args);
    }
}
*/
int main()
{
    char *str = "huy";
    printf("%10s", str);
    //ft_printf("her");
}
