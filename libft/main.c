/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:32:26 by errero            #+#    #+#             */
/*   Updated: 2021/08/03 17:23:39 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*str;
	char	c;

	str = "Hola mundo";
	c = 'f';
	printf("'%s' len = %zu\n", str, ft_strlen(str));
	printf("'%c' is alpha: ", c);
	if (ft_isalpha(c))
		printf("OK!\n");
	else
		printf("ERROR!\n");
	printf("'%c' is digit: ", c);
	if (ft_isdigit(c))
		printf("OK!\n");
	else
		printf("ERROR!\n");
	printf("'%c' is alnum: ", c);
	if (ft_isalnum(c))
		printf("OK!\n");
	else
		printf("ERROR!\n");
	printf("'%c' is ascii: ", c);
	if (ft_isascii(c))
		printf("OK!\n");
	else
		printf("ERROR!\n");
	printf("'%c' is print: ", c);
	if (ft_isprint(c))
		printf("OK!\n");
	else
		printf("ERROR!\n");
	printf("memcmp: ", c);
	printf("|%s|\n", ft_memcmp("HOLA mundo", "HOLA mundo", 6));
	printf("|%s|\n", memcmp("HOLA mundo", "HOLA mundo", 6));
}
