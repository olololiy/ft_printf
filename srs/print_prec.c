
#include "../includes/lib_printf.h"

static void	without_d(char *str_d, int len_d, struct t_flags *flags)
{
	while (flags->width > len_d && (flags->width > flags->dot))
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
	while (flags->dot > len_d)
	{
		flags->dot--;
		write(1, "0", 1);
		flags->result++;
	}
	write(1, str_d, len_d);
	flags->result = flags->result + len_d;
}

static void	zero_d(char *str_d, int len_d, struct t_flags *flags)
{
	while (flags->dot < flags->width && flags->width > len_d && flags->dot > -1)
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
	while (flags->dot > len_d || flags->width > len_d)
	{
		flags->dot--;
		write(1, "0", 1);
		flags->result++;
		flags->width--;
	}
	write(1, str_d, len_d);
	flags->result = flags->result + len_d;
}

static void	minus_d(char *str_d, int len_d, struct t_flags *flags)
{
	while (flags->dot > len_d)
	{
		flags->dot--;
		flags->width--;
		write(1, "0", 1);
		flags->result++;
	}
	write(1, str_d, len_d);
	flags->result = flags->result + len_d;
	while (flags->width > len_d && (flags->width > flags->dot))
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
}

void	print_prec(struct t_flags *flags)
{
	char	*str_d ;
	int		len_d;

	str_d = "%";
	len_d = 1;
	if (flags->dot == 0)
	{
		while (flags->width-- > 0)
		{
			write(1, " ", 1);
			flags->result++;
		}
	}
	else if (!flags->minus && !flags->zero)
		without_d(str_d, len_d, flags);
	else if (!flags->minus && flags->zero)
		zero_d(str_d, len_d, flags);
	else if (flags->minus && !flags->zero)
		minus_d(str_d, len_d, flags);
}
