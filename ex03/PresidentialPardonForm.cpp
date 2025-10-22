/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:14:29 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/22 20:16:50 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _reqIn(25), _reqExec(5), AForm("PresidentialPardon", 25, 5) {

};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): 
	_reqIn(25), _reqExec(5), _target(target), AForm("PresidentialPardon", 25, 5){

};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	_reqIn(copy._reqIn), _reqExec(copy._reqExec), _target(copy._target){

};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if (this != &copy)
		*this = copy;
	return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm(){

};

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
	{
		std::cout << this->getName();
		throw(AForm::FormNotSigned());
	}
	if (executor.getGrade() >= this->_reqExec)
		throw(Bureaucrat::GradeTooLowException());
	else
		std::cout << this->_target << " ha been pardoned by Zaphod Beeblebrox" << std::endl;
};
