/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:56 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/31 15:06:38 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <zconf.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flags
{
	char			type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				result;
	int				i;
	int				space;
}					t_flags;

t_flags				ft_init_flags(void);
int					ft_printf(const char *str, ...);
void				print_c(t_flags *flags, va_list args);
void				print_str(t_flags *flags, va_list args);
void				print_xx(t_flags *flags, va_list args);
void				print_dd(t_flags *flags, va_list args);
int					ft_strlen(char *str);
int					ft_isdigit(int c);
void				ft_putchar(char c);
char				*ft_itoa(long int n);
char				*ft_itoa_for_xx(unsigned int n, t_flags *flags);
int				obrabot_ochka(const char *str, t_flags *flags,
		va_list args);
char				*ft_itoa_for_p(unsigned long int n);
void				print_p(t_flags *flags, va_list args);
void				print_u(t_flags *flags, va_list args);
char				*ft_itoa_u(unsigned int n);
void				print_prec(t_flags *flags);
#endif
