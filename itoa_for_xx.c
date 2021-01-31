/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:25:58 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/31 14:14:11 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		countdigits(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static	char	*digtochar(unsigned int n, int colchar, t_flags *flags)
{
	char			*anumb;
	unsigned int	t_xx;
	int				tt_xx;

	if (!(anumb = malloc(sizeof(char) * (colchar + 1))))
		return (0);
	anumb[colchar] = '\0';
	colchar--;
	while (n)
	{
		t_xx = (n % 16);
		tt_xx = (int)t_xx;
		if (tt_xx > 9 && flags->type == 'x')
			anumb[colchar] = tt_xx + 'a' - 10;
		else if (tt_xx > 9 && flags->type == 'X')
			anumb[colchar] = tt_xx + 'A' - 10;
		else
			anumb[colchar] = tt_xx + '0';
		n = n / 16;
		colchar--;
	}
	return (anumb);
}

char			*ft_itoa_for_xx(unsigned int n, t_flags *flags)
{
	char	*anumb;
	int		colchar;

	if (n == 0)
	{
		anumb = malloc(sizeof(char) * (2));
		anumb[0] = '0';
		anumb[1] = '\0';
		return (anumb);
	}
	colchar = countdigits(n);
	anumb = digtochar(n, colchar, flags);
	return (anumb);
}
