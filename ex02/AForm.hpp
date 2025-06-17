/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:58 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 12:10:56 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
    public:
        AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
        AForm(const AForm& ref);
        AForm& operator=(const AForm &ref);
        virtual ~AForm();

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
		
		class FormNotSignedException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& stream, const AForm& f);
