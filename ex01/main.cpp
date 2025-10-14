/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 19:22:42 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	try
	{
		Bureaucrat *b1 = new Bureaucrat("Bulbasaur", 1);
		b1->decrementGrade();
		
		Form *f1 = new Form("attack", 3, 3);
		b1->signForm(*f1);
		
		delete (b1);
		delete (f1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}