/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:27:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/12 23:49:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal*	animal = new Animal();
	const Animal*	cat = new Cat();
	const Animal*	dog = new Dog();

	std::cout << "DISPLAY THE TYPES OF EACH VARIABLE" << std::endl;
	std::cout << "animal variable is of type " << animal->getType() << "."
		<< std::endl;
	std::cout << "cat variable is of type " << cat->getType() << "."
		<< std::endl;
	std::cout << "dog variable is of type " << dog->getType() << "."
		<< std::endl;
	std::cout << "----------------------------------------------------"
		<< std::endl;

	std::cout << "ANIMALS MAKING SOUNDS" << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
}
