/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:17:26 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/17 14:35:36 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& ref);
		Intern& operator=(const Intern& ref);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);

		class InvalidFormNameException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

typedef AForm* (*ptfForm) (const std::string& target);

struct FormLink
{
	std::string	name;
	ptfForm 	func;
};