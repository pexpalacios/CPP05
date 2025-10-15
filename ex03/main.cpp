/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/15 15:45:28 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main (void)
{
	std::srand(std::time(0));

	try
	{
		std::cout << "=== Constructors ===" << std::endl;
		Intern random;
		AForm* r;

		r = random.makeForm("robotomy request", "bender");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}