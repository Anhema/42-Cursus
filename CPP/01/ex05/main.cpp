/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:04:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/16 16:56:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen	karen;
	
	karen.complain("TEST");
	karen.complain("DEBUG");
	karen.complain("debug_test");
	karen.complain("INFO");
	karen.complain("inf");
	karen.complain("WARNING");
	karen.complain("ERROR");
	return (0);
}
