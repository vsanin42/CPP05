/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:11:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 10:12:16 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& ref);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ref);
        ~ShrubberyCreationForm();

		void execute(Bureaucrat const& executor) const;
};
