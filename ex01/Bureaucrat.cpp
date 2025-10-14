/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:54:48 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 18:45:42 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("defaultBureaucrat"), grade(150) {
	std::cout << "Default bureaucrat with grade 150 created" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->grade = grade;
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " created" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name), grade(copy.grade) {
	std::cout << "Copy bureaucrat " << this->name << " with grade " << this->grade << " created" << std::endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
	{
		*this = copy;
	}
	std::cout << "Operator assigned bureaucrat " << this->name << " with grade " << this->grade << " created" << std::endl;
	return (*this);
};

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " destroyed" << std::endl;
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

std::string Bureaucrat::getName() const
{
	return (this->name);	
};

int Bureaucrat::getGrade() const
{
	return (this->grade);	
};

void Bureaucrat::decrementGrade()
{
	this->grade++;
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << this->name << "'s grade has been decremented to " << this->grade << std::endl;	
};

void Bureaucrat::incrementGrade()
{
	this->grade--;
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	std::cout << this->name << "'s grade has been incremented to " << this->grade << std::endl;
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
