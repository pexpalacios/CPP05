/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:59:37 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/22 19:50:34 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : 
	_name("default"), _signed(false), _gradeIn(150), _gradeExec(150) {
	if (this->_gradeIn < 1 || this->_gradeExec < 1)
	{
		std::cout << this->getName() << " can't be made: ";
		throw (Form::GradeTooHighException());
	}
	if (this->_gradeIn > 150 || this->_gradeExec > 150)
	{
		std::cout << this->getName() << " can't be made: ";
		throw (Form::GradeTooLowException());
	}
	std::cout << "Form default constructor called" << std::endl;
};

Form::Form(const std::string name, int gradeIn, int gradeExec): 
	_name(name), _signed(false), _gradeIn(gradeIn), _gradeExec(gradeExec) {
	if (this->_gradeIn < 1 || this->_gradeExec < 1)
	{
		std::cout << this->getName() << " can't be made: ";
		throw (Form::GradeTooHighException());
	}
	if (this->_gradeIn > 150 || this->_gradeExec > 150)
	{
		std::cout << this->getName() << " can't be made: ";
		throw (Form::GradeTooLowException());
	}
	std::cout << "Form constructor called" << std::endl;
};

Form::Form(const Form &copy):
	_name(copy._name), _signed(copy._signed), _gradeIn(copy._gradeIn), _gradeExec(copy._gradeExec) {
	if (this->_gradeIn < 1 || this->_gradeExec < 1)
	{
		std::cout << this->getName() << " can't be made: ";
		throw (Form::GradeTooHighException());
	}
	if (this->_gradeIn > 150 || this->_gradeExec > 150)
	{
		std::cout << this->getName() << " can't be made: ";
		throw (Form::GradeTooLowException());
	}
	std::cout << "Form copy constructor called" << std::endl;
};

Form &Form::operator=(const Form &copy){

	if (this != &copy)
	{
		*this = copy;
	}
	std::cout << "Form copy assigment called" << std::endl;
	return (*this);
};

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
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
	return ("form's grade too high");
};

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("form's grade too low");
};

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_gradeIn)
	{
		this->_signed = true;	
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << ": ";
		throw(Bureaucrat::GradeTooLowException());
	}
		
};

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
	out << obj.getName() << ", form grade to sign " << obj.getGradeIn() << ", grade to execute " << obj.getGradeExec() << std::endl;
	return (out);
};