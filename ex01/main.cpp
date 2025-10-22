/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/22 19:56:31 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	try
	{
		Bureaucrat *b1 = new Bureaucrat("Bulbasaur", 1);
		Bureaucrat *b2 = new Bureaucrat("Squirtle", 4);
		
		Form *f1 = new Form("attack", 3, 3);
		b1->signForm(*f1);
		b2->signForm(*f1);
		
		delete (b1);
		delete (b2);
		delete (f1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}