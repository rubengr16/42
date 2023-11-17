/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/17 18:26:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTE_GRADE,
		"ShrubberyCreatioTarget")
{
	std::cout << "[Default Constructor] ShrubberyCreationForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& sCForm):
	AForm(sCForm)
{
	std::cout << "[Copy Constructor] ShrubberyCreationForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[Destructor] ShrubberyCreationForm: named as "
		<< this->_name << " is being deleted" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& sCForm)
{
	std::cout << "[Copy Assignment Operator] ShrubberyCreationForm: named as "
		<< this->_name << " has been copy assigned. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	ShrubberyCreationForm::execute(void)
{
	std::cout << "              / / /" << std::endl;
	std::cout << "            /        /  /     //    /" << std::endl;
	std::cout << "         /       O         /         /  /" << std::endl;
	std::cout << "        /                /" << std::endl;
	std::cout << "      /     O     O   /                //" << std::endl;
	std::cout << "       /          /       O    /            /" << std::endl;
	std::cout << "        /   O   O     '/,        / /      O  /" << std::endl;
	std::cout << "        /      /       'b  O   * /" << std::endl;
	std::cout << "         / O  /    O     '$    //      O    //" << std::endl;
	std::cout << "        /    /           $:   /:   O       /" << std::endl;
	std::cout << "      //      /  //      */  @):       /   / /" << std::endl;
	std::cout << "           O       /     :@,@):   ,/**:'   /" << std::endl;
	std::cout << "       /      /,         :@@*: //**'     /   /" << std::endl;
	std::cout << "                '/o/    /:(@'/@*'  /" << std::endl;
	std::cout << "        /  /   O   'bq,//:,@@*'   ,*      /  /" << std::endl;
	std::cout << "                   ,p$q8,:@)'  /p*'  O   /" << std::endl;
	std::cout << "            /  O  '  / '@@Pp@@*'    /  /" << std::endl;
	std::cout << "             /  / //    Y7'.'  O  / O/" << std::endl;
	std::cout << "                       :@):." << std::endl;
	std::cout << "    tree              .:@:'." << std::endl;
	std::cout << "^^^^O^^^^O^^^^O^^^^O.::(@:.O^^^^O^^^^" << std::endl;
}

