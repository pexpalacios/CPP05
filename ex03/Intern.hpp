/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:24:39 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/15 15:41:53 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <map>
#include <functional>
#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();

	AForm *makeForm(std::string form, std::string target);
};

#endif