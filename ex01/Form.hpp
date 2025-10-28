/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:37:01 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/27 18:35:22 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeIn;
	const int _gradeExec;

public:
	Form();
	Form(const std::string name, int gradeIn, int gradeExec);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	std::string getName() const;
	bool getSigned() const;
	int getGradeIn() const;
	int getGradeExec() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, Form const &obj);

#endif