/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:21:49 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 15:05:28 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		const std::string	name;
		bool				_signed;
		const u_int16_t		grade;
		const u_int16_t		exec;
	public:
		Form(void);
		Form(std::string name, u_int16_t grade, u_int16_t exec);
		Form(Form const & src);
		~Form();

		Form & operator=(const Form & rhs);

		std::string			getName(void) const;
		u_int16_t			getGrade(void) const;
		u_int16_t			getExec(void) const;
		bool				getSigned(void);
		void				beSigned(Bureaucrat &target);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

		class NotValidFormException: public std::exception
		{
			public:
				virtual const char* what() const throw() // understand better
				{
					return ("Entered form type is not valid");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Form & i);

#endif
