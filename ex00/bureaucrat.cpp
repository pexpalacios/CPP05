/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:54:48 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/13 18:48:37 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("defaultBureaucrat"), grade(150) {
	
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name), grade(copy.grade) {

};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
};

Bureaucrat::~Bureaucrat() {

};

////////

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade invalid: bureaucrat's grade can't be above 1");
};

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade invalid: bureaucrat's grade can't be below 150");
};
