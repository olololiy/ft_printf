//
// Created by Violet Furr on 1/28/21.
//


#include "../../includes/lib_printf.h"

static	int		countdigits(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n > 0)
		n = n * (-1);
	while (n < 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*digtochar(int n, int colchar)
{
	char	*anumb;

	if (!(anumb = malloc(sizeof(char) * (colchar + 1))))
		return (0);
	anumb[colchar] = '\0';
	colchar--;
	if (n < 0)
	{
		anumb[0] = '-';
	}
	else
		n = n * (-1);
	while (n)
	{
		anumb[colchar] = (n % 10) * (-1) + '0';
		n = n / 10;
		colchar--;
	}
	return (anumb);
}

char			*ft_itoa_dd(int n)
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
	//if (!n)
	//	return (NULL);
	colchar = countdigits(n);
	anumb = digtochar(n, colchar);
	return (anumb);
}
