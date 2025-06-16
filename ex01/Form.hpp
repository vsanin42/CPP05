/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:58 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 14:53:21 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
    public:
        Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
        Form(const Form& ref);
        Form &operator=(const Form &ref);
        ~Form();

		static int validateGrade(const int grade);
		void beSigned(const Bureaucrat& ref);
		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
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

std::ostream& operator<<(std::ostream& stream, const Form& f);
