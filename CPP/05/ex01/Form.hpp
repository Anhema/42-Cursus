/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:59:52 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 16:03:58 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				_signed;
		const u_int16_t		exec;
		const u_int16_t		grade;
	public:
		Form(void);
		Form(std::string name, u_int16_t grade, u_int16_t exec);
		Form(Form const & src);
		~Form();

		Form & operator=(const Form & rhs);

		std::string	getName(void) const;
		u_int16_t	getGrade(void) const;
		u_int16_t	getExec(void) const;
		bool		getSigned(void);
		void		beSigned(Bureaucrat &target);
		void		execute(Bureaucrat const &executor) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw() // understand better
				{
					return ("Form error, grade too high [1-150]");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw() // understand better
				{
					return ("Form error, grade too low [1-150]");
				}
		};
		class FormFirmedException: public std::exception
		{
			public:
				virtual const char* what() const throw() // understand better
				{
					return ("form already firmed");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Form & i);

#endif
