/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 17:11:22 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "~~~ OCF ~~~\n";
		Form a;
		std::cout << "a: " << a << std::endl;

		Form b("biba", 2, 149);
		std::cout << "b: " << b << std::endl;

		a = b;
		std::cout << "a: " << a << std::endl;

		Form c(b);
		std::cout << "c: " << c << std::endl;
	}
	{
		std::cout << "\n~~~ Exceptions ~~~\n";
		/* 1 */
		std::cout << "to sign 0, to exec 50" << std::endl;
		try {
			Form a("biba", 0, 50);
		}
		catch (const Form::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Form::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}

		/* 2 */
		std::cout << "to sign 50, to exec 0" << std::endl;
		try {
			Form b("boba", 50, 0);
		}
		catch (const Form::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Form::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}

		/* 3 */
		std::cout << "to sign 1, to exec 151" << std::endl;
		try {
			Form a("biba", 1, 151);
		}
		catch (const Form::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Form::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}

		/* 4 */
		std::cout << "to sign 151, to exec 1" << std::endl;
		try {
			Form b("boba", 151, 1);
		}
		catch (const Form::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Form::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}
	}
	{
		std::cout << "\n~~~ Signing ~~~\n";
		Form form("Declaration of Independence", 50, 25);
		std::cout << form << std::endl;

		Bureaucrat biba("biba", 51);
		Bureaucrat boba("boba", 10);
		std::cout << biba << std::endl;
		std::cout << boba << std::endl;
		
		std::cout << "\nbiba attempts to sign the form..." << std::endl;
		biba.signForm(form);
		std::cout << form << std::endl;
		
		std::cout << "\nbiba gets a promotion..." << std::endl;
		biba.raiseGrade();
		std::cout << biba << std::endl;
		
		std::cout << "\nboba attempts to sign the form (again)..." << std::endl;
		biba.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nboba attempts to sign the form..." << std::endl;
		boba.signForm(form);
		std::cout << form << std::endl;
	}
	return 0;
}
