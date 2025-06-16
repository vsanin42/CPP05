/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:22:54 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 16:00:35 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& newName, int newGrade);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat();
		
		void signForm(Form& ref);
		
		const std::string& getName() const;
		int getGrade() const;
		void raiseGrade();
		void lowerGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
	
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);
