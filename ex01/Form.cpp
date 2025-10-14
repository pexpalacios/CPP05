/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:59:37 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 18:43:47 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"

Form::Form() : 
	_name("default"), _signed(false), _gradeIn(150), _gradeExec(150) {
	std::cout << "Defaulr constructor called" << std::endl;
};

Form::Form(const std::string name, int gradeIn, int gradeExec): 
	_name(name), _signed(false), _gradeIn(gradeIn), _gradeExec(gradeExec) {
	std::cout << "Constructor called" << std::endl;
};

Form::Form(const Form &copy):
	_name(copy._name), _signed(copy._signed), _gradeIn(copy._gradeIn), _gradeExec(copy._gradeExec) {
	std::cout << "Copy constructor called" << std::endl;
};

Form &Form::operator=(const Form &copy){

	if (this != &copy)
	{
		*this = copy;
	}
	std::cout << "Copy assigment called" << std::endl;
	return (*this);
};

Form::~Form() {
	std::cout << "Destructor called" << std::endl;
};

///

std::string Form::getName() const {
	return (this->_name);
};

bool Form::getSigned() const {
	return (this->_signed);
};

int Form::getGradeIn() const {
	return (this->_gradeIn);
};

int Form::getGradeExec() const {
	return (this->_gradeExec);
};

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade invalid: form's grade can't be above 1");
};

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade invalid: form's grade can't be below 150");
};

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_gradeIn)
	{
		this->_signed = true;	
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because: " << std::endl;
		throw(Form::GradeTooLowException());
	}
		
};

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
	out << obj.getName() << ", form grade to sign " << obj.getGradeIn() << ", grade to execute " << obj.getGradeExec() << std::endl;
	return (out);
};