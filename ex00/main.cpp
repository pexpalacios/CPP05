/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:31:42 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/13 18:49:17 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

int main (void)
{
	try
	{
		Bureaucrat *uno = new Bureaucrat("Bulbasaur", 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}