/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:14:31 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 19:58:43 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _reqIn(72), _reqExec(45), AForm() {

};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): 
	_reqIn(72), _reqExec(45), _target(target), AForm(){

};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): 
	_reqIn(copy._reqIn), _reqExec(copy._reqExec){

};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if (this != &copy)
		*this = copy;
	return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm(){

};

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() >= this->_reqExec)
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << "*drilling noises*" << std::endl;
		int result = std::rand() % 2;
		if (result == 1)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy failed :(" << std::endl;
	}
};