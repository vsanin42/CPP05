/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:13:00 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 12:04:38 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref), target(ref.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
    if (this != &ref)
	{
		AForm::operator=(ref);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::cout << "Shrubbery execution called..." << std::endl;
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::string filename = target + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open())
	{
		file << 
		"          &&& &&  & &&\n"
		"	   && &\\/&\\|& ()|/ @, &&\n"
		"	   &\\/(/&/&||/& /_/)_&/_&\n"
		"   &() &\\/&|()|/&\\/ '%' & ()\n"
		"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
		"&&   && & &| &| /& & % ()& /&&\n"
		" ()&_---()&\\&\\|&&-&&--%---()~\n"
		"	  &&     \\|||\n"
		"	  		  |||\n"
		"		  	  |||\n"
		"			  |||\n"
		"	  , -=-~  .-^- _\n"
		"ejm97         `\n";

		file.close();
	}
	else
		std::cout << "Error while opening the file." << "\n";
}