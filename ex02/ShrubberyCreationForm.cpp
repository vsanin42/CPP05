#include "ShrubberyCreationForm.hpp"

// Default constructor
Shrubberycreationform::Shrubberycreationform(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Shrubberycreationform::Shrubberycreationform(const Shrubberycreationform &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Shrubberycreationform &Shrubberycreationform::operator=(const Shrubberycreationform &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Shrubberycreationform::~Shrubberycreationform(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

