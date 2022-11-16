/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:19:04 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/15 20:52:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void	is_int(char *str)
{
	int		i = 0;
	bool	isInt = true;
	int		dot = 0;
	int		f = 0;

	if (str[0] == '-')
		i = 1;
	if (str[0] == '.' || str[0] == 'f')
		isInt = false;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')) && !(str[i] == '.' || str[i] == 'f'))
		{
			isInt = false;
			break;
		}
		if (str[i] == '.')
			dot++;
		if (str[i] == 'f')
			f++;
		i++;
	}
	if ((isInt && dot == 1 && f == 1) || (isInt && dot == 0 && f == 0))
	{
		int i = static_cast<int>(std::stod(str));
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void	is_char(char *str)
{
	int		i = 0;
	bool	isInt = true;
	int		dot = 0;
	int		f = 0;

	if (str[0] == '-')
		i = 1;
	if (str[0] == '.' || str[0] == 'f')
		isInt = false;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')) && !(str[i] == '.' || str[i] == 'f'))
		{
			isInt = false;
			break;
		}
		if (str[i] == '.')
			dot++;
		if (str[i] == 'f')
			f++;
		i++;
	}
	if ((isInt && dot == 1 && f == 1) || (isInt && dot == 0 && f == 0))
	{
		double i = static_cast<double>(std::stod(str));
		unsigned const char c = static_cast<unsigned const char>(i);
		if (std::isprint(i))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void	is_float(char *str)
{
	int		i = 0, dot = 0, f = 0;
	bool	isInt = true;

	if (str[0] == '-')
		i = 1;
	if (str[0] == '.' || str[0] == 'f')
		isInt = false;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')) && !(str[i] == '.' || str[i] == 'f'))
		{
			isInt = false;
			break;
		}
		if (str[i] == '.')
			dot++;
		if (str[i] == 'f')
			f++;
		i++;
	}
	if ((isInt && dot == 1 && f == 1) || (isInt && dot == 0 && f == 0))
	{
		float ff = static_cast<float>(std::stod(str));
		std::cout << "float: " << ff << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
}

void	is_double(char *str)
{
	int		i = 0;
	bool	isInt = true;
	int		dot = 0;
	int		f = 0;

	if (str[0] == '-')
		i = 1;
	if (str[0] == '.' || str[0] == 'f')
		isInt = false;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')) && !(str[i] == '.' || str[i] == 'f'))
		{
			isInt = false;
			break;
		}
		if (str[i] == '.')
			dot++;
		if (str[i] == 'f')
			f++;
		i++;
	}
	if ((isInt && dot == 1 && f == 1) || (isInt && dot == 0 && f == 0))
	{
		double d = static_cast<double>(std::stold(str));
		std::cout << "double: " << d << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Invalid input" << std::endl;
	else
	{
		std::string	_inff = "-inf";
		std::string	inff = "+inf";
		std::string	nanf = "nan";
		std::cout << std::setprecision(1) << std::fixed;
		is_char(argv[1]);
		is_int(argv[1]);
		if (!_inff.compare(argv[1]) || !inff.compare(argv[1]) || !nanf.compare(argv[1]))
			std::cout << "float: " << argv[1] << "f" << std::endl;
		else
			is_float(argv[1]);
		if (!_inff.compare(argv[1]) || !inff.compare(argv[1]) || !nanf.compare(argv[1]))
			std::cout << "double: " << argv[1] << std::endl;
		else
			is_double(argv[1]);
	}
	return (0);
}
