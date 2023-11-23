/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 19:15:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm(SCF_NAME, SCF_SIGN_GRADE, SCF_EXECUTE_GRADE,
		"ShrubberyCreationTarget")
{
	std::cout << "[Default Constructor] ShrubberyCreationForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm(SCF_NAME, SCF_SIGN_GRADE, SCF_EXECUTE_GRADE, target)
{
	std::cout << "[Constructor] ShrubberyCreationForm: named as "
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
	this->_signed = sCForm.getSigned();
	this->_target = sCForm.getTarget();
	std::cout << "[Copy Assignment Operator] ShrubberyCreationForm: named as "
		<< this->_name << " has been copy assigned. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed, which targets " << this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	ShrubberyCreationForm::execute(void) const
{
	std::ofstream	fout;

	this->checkSigned();
	fout.open((this->getTarget() + "_shrubbery").c_str(), std::ifstream::out);
	if (!fout.is_open())
		throw (FailedOpenException());
	fout << "           /'/'  //'/  '//'      //''/" << std::endl;
	fout << "        /'/    //   ///   /    ''/    /'" << std::endl;
	fout << "      /     O   / O   /   // /         //" << std::endl;
	fout << "       /          /       O    /            /" << std::endl;
	fout << "        /   O   O     '/,        / /      O  /" << std::endl;
	fout << "        /      /       'b  O   * /" << std::endl;
	fout << "         / O  /    O     '$    //      O    //" << std::endl;
	fout << "        /    /           $:   /:   O       /" << std::endl;
	fout << "      //      /  //      */  @):       /   / /" << std::endl;
	fout << "     /     O       /     :@,@):   ,/**:'   /" << std::endl;
	fout << "      '/'     /,         :@@*: //**'     /   /" << std::endl;
	fout << "         /      '/o/    /:(@'/@*'  /" << std::endl;
	fout << "        /  /   O   'bq,//:,@@*'   ,*      /  /" << std::endl;
	fout << "         // //     ,p$q8,:@)'  /p*'  O   /" << std::endl;
	fout << "              / /'' '@@Pp@@*'    /'/" << std::endl;
	fout << "                       :@):." << std::endl;
	fout << "    tree              .:@:'." << std::endl;
	fout << "^^^^O^^^^O^^^^O^^^^O.::(@:.O^^^^O^^^^" << std::endl;
	fout.close();
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	ShrubberyCreationForm::FailedOpenException::what(void)
	const throw()
{
	return ("[What] ShrubberyCreationForm: Error! Unable to open  file");
}
