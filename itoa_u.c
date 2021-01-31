/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:38:40 by vfurr             #+#    #+#             */
/*   Updated: 2021/01/31 14:15:08 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		countdigits(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*digtochar(unsigned int n, int colchar)
{
	char	*anumb;

	if (!(anumb = malloc(sizeof(char) * (colchar + 1))))
		return (0);
	anumb[colchar] = '\0';
	colchar--;
	while (n)
	{
		anumb[colchar] = (n % 10) + '0';
		n = n / 10;
		colchar--;
	}
	return (anumb);
}

char			*ft_itoa_u(unsigned int n)
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
