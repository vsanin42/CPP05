/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 17:47:36 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Intern intern;
	
	AForm* shrubbery;
	AForm* robotomy;
	AForm* pardon;
	
	shrubbery = intern.makeForm("Shrubbery", "biba");
	robotomy = intern.makeForm("Robotomy", "Gustavo Fring");
	pardon = intern.makeForm("Pardon", "buba");

	std::cout << std::endl;
	Bureaucrat waltuh("Walter White", 1);
	Bureaucrat salamanca("Hector Salamanca", 1);
	salamanca.signForm(*robotomy);
	waltuh.executeForm(*robotomy);
	std::cout << std::endl;

	delete shrubbery;
	delete robotomy;
	delete pardon;

	AForm* invalid;
	
	try {
		invalid = intern.makeForm("invalid", "text");
	} catch (const Intern::InvalidFormNameException& e) {
		std::cout << "Intern failed to make a form: " << e.what();
	}
	
	return 0;
}
