/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:37:52 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/31 13:38:22 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		countdigits(unsigned long int n)
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

static	char	*digtochar(unsigned long int n, int colchar)
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
		if (tt_xx > 9)
			anumb[colchar] = tt_xx + 'a' - 10;
		else
			anumb[colchar] = tt_xx + '0';
		n = n / 16;
		colchar--;
	}
	return (anumb);
}

char			*ft_itoa_for_p(unsigned long int n)
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
	anumb = digtochar(n, colchar);
	return (anumb);
}
