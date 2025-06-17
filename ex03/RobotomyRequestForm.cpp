/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:02:05 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/16 21:57:21 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref), target(ref.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    if (this != &ref)
	{
		AForm::operator=(ref);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "Robotomy execution called..." << std::endl;
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "BZZZZZZZZZZZZZZZZ..." << std::endl;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	std::srand(tv.tv_usec);
	if (std::rand() % 2)
		std::cout << target << " robotomized successfully :)" << std::endl;
	else
		std::cout << "Robotomy on " << target << " failed :(" << std::endl;
}
