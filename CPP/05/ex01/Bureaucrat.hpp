/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:58:37 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 20:33:18 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string 	name;
		u_int16_t			grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, u_int16_t grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat & operator=(const Bureaucrat & rhs);
		
		std::string	getName(void) const;
		u_int16_t	getGrade(void) const;
		void		increment(void);
		void		decrement(void);
		void		signForm(Form &form);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw() // understand better
				{
					return ("Bureaucrat error, grade too high [1-150]");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw() // understand better
				{
					return ("Bureaucrat error, grade too low [1-150]");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & i);

#endif
