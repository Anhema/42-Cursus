#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int	ft_print_str(char *str);
int	ft_print_char(int c);
int	ft_print_hexadecimal(unsigned int i);
int	ft_print_numbers(int number);
int	ft_print_unumber(unsigned int n);

int	ft_putlhex(unsigned int adr);


#endif