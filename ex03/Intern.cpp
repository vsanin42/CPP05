/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:31:06 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 17:36:00 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& ref) { (void)ref; }

Intern& Intern::operator=(const Intern& ref)
{
	(void)ref;
	return *this;
}

Intern::~Intern() {}

AForm* makeShrubbery(const std::string& target) { return (new ShrubberyCreationForm(target)); }

AForm* makeRobotomy(const std::string& target) { return (new RobotomyRequestForm(target)); }

AForm* makePardon(const std::string& target) { return (new PresidentialPardonForm(target)); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	FormLink formNameArray[] = {
		{ "Shrubbery", &makeShrubbery },
		{ "Robotomy", &makeRobotomy },
		{ "Pardon", &makePardon }
	};
	
	int i;
	for (i = 0; i < 3; i++)
	{
		if (formNameArray[i].name == formName)
		{
			std::cout << "Intern creates \"" << formName << "\"" << std::endl;
			return (formNameArray[i].func)(target);
		}
	}
	if (i == 3)
		throw Intern::InvalidFormNameException();
	return NULL;
}

const char* Intern::InvalidFormNameException::what() const throw ()
{
	return "No form matched the provided name.\n";
}
