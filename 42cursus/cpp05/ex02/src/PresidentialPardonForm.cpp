/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 13:50:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
PresidentialPardonForm::PresidentialPardonForm(void):
	AForm(PPF_NAME, PPF_SIGN_GRADE, PPF_EXECUTE_GRADE, "PresidentialTarget")
{
	std::cout << "[Default Constructor] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm(PPF_NAME, PPF_SIGN_GRADE, PPF_EXECUTE_GRADE, target)
{
	std::cout << "[Constructor] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& pPForm):
	AForm(pPForm)
{
	std::cout << "[Copy Constructor] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[Destructor] PresidentialPardonForm: named as "
		<< this->_name << " is being deleted" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
PresidentialPardonForm&	PresidentialPardonForm::operator=(
	const PresidentialPardonForm& pPForm)
{
	this->_signed = pPForm.getSigned();
	this->_target = pPForm.getTarget();
	std::cout << "[Copy Assignment Operator] PresidentialPardonForm: named as "
		<< this->_name << " has been copy assigned. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkSigned();
	this->checkExecute(executor.getGrade());
	std::cout << this->getTarget() << " has been pardoned by Zaphod "
		<< "Beeblebrox" << std::endl;
}
