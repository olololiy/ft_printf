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

typedef	struct		s_flags
{
    int				already_print;
    char 				type;
    int				width;
    int				minus;
    int				zero;
    int				dot;
    int				star;
    int             result;
}					t_flags;

t_flags		ft_init_flags(void);

#endif