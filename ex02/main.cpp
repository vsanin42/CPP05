/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 12:05:06 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "~~~ Shrubbery Creation ~~~" << std::endl;
		ShrubberyCreationForm defShrubbery;
		std::cout << defShrubbery << std::endl;

		ShrubberyCreationForm shrubbery("bobik");
		std::cout << shrubbery << std::endl;
		
		Bureaucrat biba("biba", 1);
		Bureaucrat boba("boba", 150);
		Bureaucrat signClerk("Clerk lvl 1", 150);
		Bureaucrat signBoss("Boss lvl 100", 15);

		boba.executeForm(shrubbery);
		signClerk.signForm(shrubbery);
		signBoss.signForm(shrubbery);

		std::cout << shrubbery << std::endl;
		boba.executeForm(shrubbery);
		biba.executeForm(shrubbery);
	}
	{
		std::cout << "\n~~~ Robotomy Request ~~~" << std::endl;
		RobotomyRequestForm defRobotomy;
		std::cout << defRobotomy << std::endl;

		RobotomyRequestForm robotomy("bobik");
		std::cout << robotomy << std::endl;
		
		Bureaucrat biba("biba", 1);
		Bureaucrat boba("boba", 150);
		Bureaucrat signClerk("Clerk lvl 1", 150);
		Bureaucrat signBoss("Boss lvl 100", 15);

		boba.executeForm(robotomy);
		signClerk.signForm(robotomy);
		signBoss.signForm(robotomy);

		std::cout << robotomy << std::endl;
		boba.executeForm(robotomy);
		biba.executeForm(robotomy);
	}
	{
		std::cout << "\n~~~ Presidential Pardon ~~~" << std::endl;
		PresidentialPardonForm defPardon;
		std::cout << defPardon << std::endl;

		PresidentialPardonForm pardon("bobik");
		std::cout << pardon << std::endl;
		
		Bureaucrat biba("biba", 1);
		Bureaucrat boba("boba", 150);
		Bureaucrat signClerk("Clerk lvl 1", 150);
		Bureaucrat signBoss("Boss lvl 100", 15);

		boba.executeForm(pardon);
		signClerk.signForm(pardon);
		signBoss.signForm(pardon);

		std::cout << pardon << std::endl;
		boba.executeForm(pardon);
		biba.executeForm(pardon);
	}
	return 0;
}
