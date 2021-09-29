/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:29:52 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/21 19:03:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_numbers(int number);
int		ft_pointer_to_str(size_t base);
int		ft_print_str(char *str);
int		ft_print_unumber(unsigned int n);
int		ft_print_pointer(size_t p);
int		ft_print_hexadecimal(unsigned int i, char c);

#endif
