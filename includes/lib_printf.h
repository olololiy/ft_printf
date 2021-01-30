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
    char 				type;
    int				width;
    int				minus;
    int				zero;
    int				dot;
    int             result;
    int 			i;
    int 			space;
}					t_flags;

t_flags		ft_init_flags(void);
int ft_printf(const char *str, ... );
void print_c(struct t_flags *flags, va_list args);
void print_str(struct t_flags *flags, va_list args);
void	print_xX(struct t_flags *flags, va_list args);
void print_dd(/*const char *str, */struct t_flags *flags, va_list args);
		int	ft_strlen( char *str);
int	ft_isdigit(int c);
void ft_putchar(char c);
char		*ft_itoa(long int n);
char			*ft_itoa_for_xX(unsigned int n, struct t_flags *flags);
void obrabot_ochka(const char *str, struct t_flags *flags, va_list args);
char			*ft_itoa_for_p(unsigned long int n);
void	print_p(struct t_flags *flags, va_list args);
void	print_u(struct t_flags *flags, va_list args);
char			*ft_itoa_u(unsigned int n);
void	print_prec(struct t_flags *flags);




#endif