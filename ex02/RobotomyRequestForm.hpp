/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:05:51 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 19:39:46 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	int _reqIn;
	int _reqExec;
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	void execute (Bureaucrat const &executor) const;
};
#endif