/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/22 19:17:57 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
	try
	{
		Bureaucrat *b1 = new Bureaucrat("Bulbasaur", 1);
		b1->decrementGrade();
		std::cout << *b1 << std::endl;
		Bureaucrat *b3 = new Bureaucrat();
		b3 = b1;
		Bureaucrat *b5 = new Bureaucrat(*b1);
		Bureaucrat *b4 = new Bureaucrat("Mew", 151);
		
		delete (b1);
		delete (b3);
		delete (b4);
		delete (b5);		
		//Bureaucrat *b2 = new Bureaucrat("Arceus", 0);
		//delete (b2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}