/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:29:09 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/21 19:00:01 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	set_value(char *format, int i, va_list arg)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'c')
		count = ft_print_char(va_arg(arg, int));
	if (format[i + 1] == 's')
		count = ft_print_str(va_arg(arg, char *));
	if (format[i + 1] == 'p')
		count = ft_print_pointer(va_arg(arg, size_t));
	if (format[i + 1] == 'd')
		count = ft_print_numbers(va_arg(arg, int));
	if (format[i + 1] == 'i')
		count = ft_print_numbers(va_arg(arg, int));
	if (format[i + 1] == 'u')
		count = ft_print_unumber(va_arg(arg, unsigned int));
	if (format[i + 1] == 'x')
		count = ft_print_hexadecimal(va_arg(arg, unsigned int), 'x');
	if (format[i + 1] == 'X')
		count = ft_print_hexadecimal(va_arg(arg, unsigned int), 'X');
	if (format[i + 1] == '%')
		count = ft_print_char('%');
	return (count);
}

int	put_format(const char *format, va_list arg)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = ft_strdup(format);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		else
		{
			count += set_value(str, i, arg);
			i++;
		}
		i++;
	}
	free(str);
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
