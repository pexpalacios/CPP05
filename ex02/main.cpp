/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/22 20:15:35 by penpalac         ###   ########.fr       */
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
		Bureaucrat *alto = new Bureaucrat("Dios", 1);
		Bureaucrat *medio = new Bureaucrat("pseudodios", 40);
		Bureaucrat *bajo = new Bureaucrat("Un tio", 150);

		ShrubberyCreationForm form1("my");
		RobotomyRequestForm form2("robototo");
		PresidentialPardonForm form3("José");
		PresidentialPardonForm form4("another president");
		std::cout << std::endl;
		form1.beSigned(*alto);
		form2.beSigned(*alto);
		form3.beSigned(*alto);
		std::cout << "=== High grade ===" << std::endl;
		alto->executeForm(form1);
		alto->executeForm(form2);
		alto->executeForm(form3);
		alto->executeForm(form4);
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