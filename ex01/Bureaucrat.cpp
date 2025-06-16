/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:23:38 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 17:02:10 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& newName, int newGrade) : name(newName)
{
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.name), grade(ref.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "womp womp can't assign const attributes :P" << std::endl;
	(void)ref;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::raiseGrade()
{
	if (getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade -= 1;
}

void Bureaucrat::lowerGrade()
{
	if (getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "Grade too high.\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Grade too low.\n";
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade();
	return stream;
}

void Bureaucrat::signForm(Form& ref)
{
	if (ref.getIsSigned())
	{
		std::cout << "\"" << ref.getName() << "\" is already signed" << std::endl;
		return ;
	}
	try {
		ref.beSigned(*this);
	} catch (const Form::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign \"" << ref.getName() << "\" because " << e.what();
	}
	if (ref.getIsSigned())
		std::cout << this->getName() << " signed \"" << ref.getName() << "\"" << std::endl;
}
