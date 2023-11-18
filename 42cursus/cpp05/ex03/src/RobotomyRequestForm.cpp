/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/18 14:43:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
RobotomyRequestForm::RobotomyRequestForm(void):
	AForm(RRF_NAME, RRF_SIGN_GRADE, RRF_EXECUTE_GRADE, "RobotomyRequestTarget")
{
	srand(time(NULL));
	std::cout << "[Default Constructor] RobotomyRequestForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm(RRF_NAME, RRF_SIGN_GRADE, RRF_EXECUTE_GRADE, target)
{
	std::cout << "[Constructor] RobotomyRequestForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& rRForm):
	AForm(rRForm)
{
	srand(time(NULL));
	std::cout << "[Copy Constructor] RobotomyRequestForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[Destructor] RobotomyRequestForm: named as "
		<< this->_name << " is being deleted" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
RobotomyRequestForm&	RobotomyRequestForm::operator=(
	const RobotomyRequestForm& rRForm)
{
	this->_signed = rRForm.getSigned();
	this->_target = rRForm.getTarget();
	std::cout << "[Copy Assignment Operator] RobotomyRequestForm: named as "
		<< this->_name << " has been copy assigned. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
AForm*	RobotomyRequestForm::factory(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

void	RobotomyRequestForm::execute(void) const
{
	this->checkSigned();
	std::cout << "Beep, beeep, bruum, bruuum..." << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been successfully robotomized"
			<< std::endl;
	else
		std::cout << this->getTarget() << " cannot be robotomized" << std::endl;
}
