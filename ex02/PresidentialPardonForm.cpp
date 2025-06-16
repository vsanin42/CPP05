/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:59:37 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 21:04:01 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref), target(ref.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    if (this != &ref)
	{
		AForm::operator=(ref);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	std::cout << "Pardon execution called..." << std::endl;
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
}
