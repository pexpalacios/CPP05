/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:01:33 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 19:03:28 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : 
	_name("default"), _signed(false), _gradeIn(150), _gradeExec(150) {
	std::cout << "Defaulr constructor called" << std::endl;
};

AForm::AForm(const std::string name, int gradeIn, int gradeExec): 
	_name(name), _signed(false), _gradeIn(gradeIn), _gradeExec(gradeExec) {
	std::cout << "Constructor called" << std::endl;
};

AForm::AForm(const AForm &copy):
	_name(copy._name), _signed(copy._signed), _gradeIn(copy._gradeIn), _gradeExec(copy._gradeExec) {
	std::cout << "Copy constructor called" << std::endl;
};

AForm &AForm::operator=(const AForm &copy){

	if (this != &copy)
	{
		*this = copy;
	}
	std::cout << "Copy assigment called" << std::endl;
	return (*this);
};

AForm::~AForm() {
	std::cout << "Destructor called" << std::endl;
};

///

std::string AForm::getName() const {
	return (this->_name);
};

bool AForm::getSigned() const {
	return (this->_signed);
};

int AForm::getGradeIn() const {
	return (this->_gradeIn);
};

int AForm::getGradeExec() const {
	return (this->_gradeExec);
};

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade invalid: AForm's grade can't be above 1");
};

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade invalid: AForm's grade can't be below 150");
};

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_gradeIn)
	{
		this->_signed = true;	
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because: " << std::endl;
		throw(AForm::GradeTooLowException());
	}
		
};

std::ostream &operator<<(std::ostream &out, AForm const &obj)
{
	out << obj.getName() << ", AForm grade to sign " << obj.getGradeIn() << ", grade to execute " << obj.getGradeExec() << std::endl;
	return (out);
};