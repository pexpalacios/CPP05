/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:54:48 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/22 20:02:24 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("defaultBureaucrat"), _grade(150) {
	if (this->_grade < 1)
	{
		std::cout << this->getName() << " can't be created: ";
		throw(Bureaucrat::GradeTooHighException());
	}
	if (this->_grade > 150)
	{
		std::cout << this->getName() << " can't be created: ";
		throw (Bureaucrat::GradeTooLowException());
	}
	std::cout << "Default bureaucrat with grade 150 created" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
	{
		std::cout << this->getName() << " can't be created: ";
		throw(Bureaucrat::GradeTooHighException());
	}
	if (this->_grade > 150)
	{
		std::cout << this->getName() << " can't be created: ";
		throw (Bureaucrat::GradeTooLowException());
	}
	std::cout << "Bureaucrat " << this->_name << " with grade " << this->_grade << " created" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
	std::cout << "Copy bureaucrat " << this->_name << " with grade " << this->_grade << " created" << std::endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
	{
		*this = copy;
	}
	std::cout << "Operator assigned bureaucrat " << this->_name << " with grade " << this->_grade << " created" << std::endl;
	return (*this);
};

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->_name << " with grade " << this->_grade << " destroyed" << std::endl;
};

////////

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("bureaucrat's grade too high");
};

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("bureaucrat's grade too low");
};

std::string Bureaucrat::getName() const
{
	return (this->_name);	
};

int Bureaucrat::getGrade() const
{
	return (this->_grade);	
};

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (_grade > 150)
	{
		std::cout << "Can't decrement " << this->_name << "'s grade: ";
		throw(Bureaucrat::GradeTooLowException());
	}
	std::cout << this->_name << "'s grade has been decremented to " << this->_grade << std::endl;	
};

void Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (_grade < 1)
	{
		std::cout << "Can't increment " << this->_name << "'s grade: ";
		throw(Bureaucrat::GradeTooHighException());
	}
	std::cout << this->_name << "'s grade has been incremented to " << this->_grade << std::endl;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
};

///////

void Bureaucrat::signForm(Form &f)
{
	f.beSigned(*this);
};
