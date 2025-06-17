/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:43 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 19:57:50 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name(""), isSigned(false), gradeToSign(150), gradeToExec(1) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) :
	name(name),
	isSigned(false),
	gradeToSign(validateGrade(gradeToSign)),
	gradeToExec(validateGrade(gradeToExec)) {}

AForm::AForm(const AForm &ref) :
	name(ref.name),
	isSigned(ref.isSigned),
	gradeToSign(ref.gradeToSign),
	gradeToExec(ref.gradeToExec) {}

AForm &AForm::operator=(const AForm &ref)
{
	std::cout << "womp womp can't assign const attributes :P" << std::endl;
	(void)ref;
	return *this;
}

AForm::~AForm() {}

int AForm::validateGrade(const int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	else
		return grade;
}

void AForm::beSigned(const Bureaucrat& ref)
{
	if (gradeToSign >= ref.getGrade())
		isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return gradeToSign; }
int AForm::getExecGrade() const { return gradeToExec; }

const char* AForm::GradeTooHighException::what() const throw ()
{
	return "Grade too high.\n";
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return "Grade too low.\n";
}

const char* AForm::FormNotSignedException::what() const throw ()
{
	return "Form not signed.\n";
}

std::ostream& operator<<(std::ostream& stream, const AForm& f)
{
	stream << "Form \"" << f.getName() << "\", grade to sign: " << f.getSignGrade()
		   << ", grade to execute: " << f.getExecGrade() << ". Signed? " << (f.getIsSigned() ? "Yes" : "No");
	return stream;
}

