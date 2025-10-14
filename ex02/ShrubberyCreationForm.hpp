/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:03:51 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 19:40:55 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	//required grades: signed 145 exec 137
	// creates a file target_shrubbery in the directory and writes ascii trees in it
private:
	int _reqIn;
	int _reqExec;
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	void execute (Bureaucrat const &executor) const;
};

#endif