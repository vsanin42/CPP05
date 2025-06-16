/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:43 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 16:42:34 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""), isSigned(false), gradeToSign(150), gradeToExec(1) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) :
	name(name),
	isSigned(false),
	gradeToSign(validateGrade(gradeToSign)),
	gradeToExec(validateGrade(gradeToExec)) {}

Form::Form(const Form &ref) :
	name(ref.name),
	isSigned(ref.isSigned),
	gradeToSign(ref.gradeToSign),
	gradeToExec(ref.gradeToExec) {}

Form &Form::operator=(const Form &ref)
{
	std::cout << "womp womp can't assign const attributes :P" << std::endl;
	(void)ref;
	return *this;
}

Form::~Form(void) {}

int Form::validateGrade(const int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else
		return grade;
}

void Form::beSigned(const Bureaucrat& ref)
{
	if (gradeToSign >= ref.getGrade())
		isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return gradeToSign; }
int Form::getExecGrade() const { return gradeToExec; }

const char* Form::GradeTooHighException::what() const throw ()
{
	return "Grade too high.\n";
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return "Grade too low.\n";
}

std::ostream& operator<<(std::ostream& stream, const Form& f)
{
	stream << "Form \"" << f.getName() << "\", grade to sign: " << f.getSignGrade()
		   << ", grade to execute: " << f.getExecGrade() << ". Signed? " << (f.getIsSigned() ? "Yes" : "No");
	return stream;
}

