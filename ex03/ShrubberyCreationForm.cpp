/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:14:33 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/15 15:17:11 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _reqIn(145), _reqExec(137), AForm("ShrubberyCreation", 145, 137) {

};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): 
	_reqIn(145), _reqExec(137), _target(target), AForm("ShrubberyCreation", 145, 137){

};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	_reqIn(copy._reqIn), _reqExec(copy._reqExec), _target(copy._target){

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
		throw(Bureaucrat::GradeTooLowException());
	else
	{
		std::string outFile = this->_target + "_shrubbery";
		std::ofstream output(outFile.c_str());
		if (output.is_open())
		{
            output << "               ,@@@@@@@,\n";
            output << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
            output << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
            output << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
            output << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
            output << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
            output << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
            output << "        |o|        | |         | | \n";
            output << "        |.|        | |         | | \n";
            output << "     \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/\n";
            output.close();
			std::cout << outFile << " created" << std::endl;
		}
		else
			std::cerr << outFile << " could not be craeted" << std::endl;
	}
};