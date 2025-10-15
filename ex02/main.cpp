/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/15 15:19:38 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{
	std::srand(std::time(0));

	try
	{
		std::cout << "=== Constructors ===" << std::endl;
		Bureaucrat *alto = new Bureaucrat("dios", 1);
		Bureaucrat *medio = new Bureaucrat("pseudodios", 40);
		Bureaucrat *bajo = new Bureaucrat("un tio", 150);

		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("robototo");
		PresidentialPardonForm form3("Steven");
		std::cout << std::endl;
		std::cout << "=== High grade ===" << std::endl;
		alto->executeForm(form1);
		alto->executeForm(form2);
		alto->executeForm(form3);
		std::cout << std::endl;
		std::cout << "=== Medium grade ===" << std::endl;
		medio->executeForm(form1);
		medio->executeForm(form2);
		medio->executeForm(form3);
		std::cout << std::endl;
		std::cout << "=== Low grade ===" << std::endl;
		bajo->executeForm(form1);
		bajo->executeForm(form2);
		bajo->executeForm(form3);
		std::cout << std::endl;
		std::cout << "=== Destructors ===" << std::endl;
		delete (alto);
		delete (medio);
		delete (bajo);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}