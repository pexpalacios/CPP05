/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:28:23 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/15 15:45:21 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &copy)
{
	*this = copy;
};

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
};

Intern::~Intern() {};

AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string options[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i;

    for (i = 0; i < 3; i++) {
        if (options[i] == form)
            break;
    }

    switch (i) {
        case 0:
            std::cout << "Intern creates a " << options[i] << " form" << std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates a " << options[i] << " form" << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates a " << options[i] << " form" << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            std::cerr << form << " type does not exist." << std::endl;
            return NULL;
    }
};
