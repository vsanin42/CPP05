/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 12:19:22 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "~~~ OCF ~~~\n";
		Bureaucrat a;
		std::cout << "a: " << a << std::endl;

		Bureaucrat b("biba", 1);
		std::cout << "b: " << b << std::endl;

		a = b;
		std::cout << "a: " << a << std::endl;

		Bureaucrat c(b);
		std::cout << "c: " << c << std::endl;
	}
	{
		std::cout << "\n~~~ Exceptions ~~~\n";
		try {
			Bureaucrat a("biba", 200);
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}

		try {
			Bureaucrat b("boba", 0);
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}
	}
	{
		std::cout << "\n~~~ Increment ~~~\n";
		Bureaucrat a("biba", 1);
		std::cout << a << std::endl;
		
		try {
			a.raiseGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}
		std::cout << a << std::endl;
		
		try {
			a.lowerGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}
		std::cout << a << std::endl;
	}
	{
		std::cout << "\n~~~ Decrement ~~~\n";
		Bureaucrat b("boba", 150);
		std::cout << b << std::endl;
		
		try {
			b.lowerGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}
		std::cout << b << std::endl;
		
		try {
			b.raiseGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception: " << e.what();
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception: " << e.what();
		}
		std::cout << b << std::endl;
	}
	return 0;
}
