/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:14:33 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 20:06:41 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _reqIn(145), _reqExec(137), AForm() {

};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): 
	_reqIn(145), _reqExec(137), _target(target), AForm(){

};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	_reqIn(copy._reqIn), _reqExec(copy._reqExec){

};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	if (this != &copy)
		*this = copy;
	return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm(){

};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() >= this->_reqExec)
		throw(AForm::GradeTooLowException());
	else
	{
		std::string outFile = this->_target + "_shrubbery";
		std::string content = "arbol";
		std::ofstream output(outFile.c_str());
		if (!output)
		{
			std::cerr << "Error creating file" << std::endl;
			exit;
		}
		output << content;
		output.close();
	}
};