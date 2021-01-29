#include "../includes/lib_printf.h"

static void	without_d(unsigned long d, char *str_d, int len_d, struct t_flags *flags)
{
	if (d < 0 && flags->dot > len_d)
		flags->width--;
	while (flags->width - 2 > len_d && (flags->width > flags->dot))
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
	if (d < 0)
	{
		write(1, "-", 1);
		flags->result++;
		str_d++;
		len_d--;
	}
	write(1, "0x", 2);
	if(*str_d == '0' && flags->dot == 0)
		len_d = 0;
	write(1, str_d, len_d);
	flags->result = flags->result + len_d + 2;
}



static void	minus_d(unsigned int d, char *str_d, int len_d, struct t_flags *flags)
{
	if (d < 0)
	{
		write(1, "-", 1);
		flags->result++;
		str_d++;
		len_d--;
		flags->width--;
	}
	while (flags->dot > len_d)
	{
		flags->dot--;
		flags->width--;
		write(1, "0", 1);
		flags->result++;
	}
	write(1, "0x", 2);
	write(1, str_d, len_d);
	flags->result = flags->result + len_d + 2;
	while (flags->width - 2 > len_d && (flags->width > flags->dot))
	{
		flags->width--;
		write(1, " ", 1);
		flags->result++;
	}
}

void	print_p(struct t_flags *flags, va_list args)
{
	unsigned long int	d;
	char	*str_d;
	int		len_d;

	d = va_arg(args, unsigned long int);
	str_d = ft_itoa_for_p(d);
	//printf("%u", d);
	//write(1, "\n", 1);
	len_d = ft_strlen(str_d);

	if (d == 0 && flags->dot == 0)
	{
		//flags->width = - 2;
		while (flags->width-- > 2)
		{
			write(1, " ", 1);
			flags->result++;
		}
	}
	if (!flags->minus && !flags->zero)
		without_d(d, str_d, len_d, flags);
	if (flags->minus && !flags->zero)
		minus_d(d, str_d, len_d, flags);
	free(str_d);
}