/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:23:38 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/24 17:43:00 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
try : name(name), grade(grade) {}
catch (const std::exception& e)
{
	// todo
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.name), grade(ref.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "womp womp can't assign const attributes :P" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::raiseGrade()
{
	// try-catch
	grade -= 1;
}

void Bureaucrat::lowerGrade()
{
	// try-catch
	grade += 1;
}
