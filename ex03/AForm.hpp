/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:01:30 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/14 20:06:38 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ctime>
#include <fstream>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeIn;
	const int _gradeExec;

public:
	AForm();
	AForm(const std::string name, int gradeIn, int gradeExec);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();

	std::string getName() const;
	bool getSigned() const;
	int getGradeIn() const;
	int getGradeExec() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const noexcept;
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const noexcept;
	};

	void beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &obj);

#endif