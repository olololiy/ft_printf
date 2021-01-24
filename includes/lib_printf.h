/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:56 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/16 00:10:59 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <zconf.h>
#include <stdlib.h>


typedef	struct		t_flags
{
    int				already_print;
    char 				type;
    int				width;
    int				minus;
    int				zero;
    int				dot;
    int				star;
    int             result;
    int 			i;
}					t_flags;

t_flags		ft_init_flags(void);
int ft_printf(const char *str, ... );
void print_c(/*const char *str, */struct t_flags *flags, va_list args);
void print_str(/*const char *str, */struct t_flags *flags, va_list args);
int	ft_strlen( char *str);
int	ft_isdigit(int c);
void ft_putchar(char c);
char		*ft_itoa(int n);
void print_d(/*const char *str, */struct t_flags *flags, va_list args);



#endif