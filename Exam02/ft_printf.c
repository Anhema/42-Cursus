#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putlstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putlnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (ft_putlstr("-2147483648"));
	if (nbr < 0)
	{
		nbr *= -1;
		len = ft_putchar('-');
	}
	if (nbr > 9)
		len += ft_putlnbr(nbr / 10);
	len += ft_putchar((nbr % 10) + 48);
	return (len);
}

int	ft_putlhex(unsigned int adr)
{
	int		len;
	char	*xbase;

	xbase = "0123456789abcdef";
	len = 0;
	if (adr >= 16)
		len += ft_putlhex(adr / 16);
	len += ft_putchar(xbase[adr % 16]);
	return (len);
	return (0);
}

int	set_value(char *format, int i, va_list arg)
{
	int	count;

	count = 0;
	if (format[i + 1] == 's')
		count = ft_putlstr(va_arg(arg, char *));
	if (format[i + 1] == 'd')
		count = ft_putlnbr(va_arg(arg, int));
	if (format[i + 1] == 'x')
		count = ft_putlhex(va_arg(arg, unsigned int));
	return (count);
}

int	put_format(const char *format, va_list arg)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		else
		{
			count += set_value((char *)format, i, arg);
			i++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	if (!format)
		return (0);
	len = 0;
	va_start(arg, format);
	len = put_format(format, arg);
	va_end(arg);
	return (len);
}