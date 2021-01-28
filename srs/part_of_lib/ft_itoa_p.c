//
// Created by Violet Furr on 1/28/21.
//

#include "../../includes/lib_printf.h"

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

static	char	*digtochar(unsigned int n, int colchar, struct t_flags *flags)
{
	char	*anumb;
	unsigned int t_xX;
	int tt_xX;

	if (!(anumb = malloc(sizeof(char) * (colchar + 1))))
		return (0);
	anumb[colchar] = '\0';
	colchar--;
	while (n)
	{
		t_xX = (n % 16);
		tt_xX = (int)t_xX; // упростить
		if (tt_xX > 9 && flags->type == 'x')
			anumb[colchar] = tt_xX + 'a' - 10;
		else if (tt_xX > 9 && flags->type == 'X')
			anumb[colchar] = tt_xX + 'A' - 10;
		else
			anumb[colchar] = tt_xX + '0';
		n = n / 16;
		colchar--;
	}
	//anumb[colchar] = 'x';
	//anumb[colchar-1] = '0';
	return (anumb);
}

char			*ft_itoa_for_p(unsigned int n, struct t_flags *flags)
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

