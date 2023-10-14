/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:27:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 22:36:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
/* ********************* CREATE A BRAIN FOR CAT AND DOG ********************* */
	std::string	ideas[] = {"GivePaw", "Make Sound", "I want to eat"};
	Brain				brain(ideas, sizeof(ideas) / sizeof(std::string));
	Cat					catWithBrain = Cat(brain);
	Dog					dogWithBrain = Dog(brain);
/* ************************ CLASSES BAD POLYMORPHISM ************************ */
	const Animal*		animal = new Animal();
	const Animal*		cat = new Cat();
	const Animal*		dog = new Dog();
/* ********************** CLASSES WITH BAD POLYMORPHISM ********************* */
	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();
/* ************************** AUXILIARY VARIABLES *************************** */
	unsigned int		i;
	std::cout << "DISPLAY THE TYPES OF ANIMAL'S OBJECT" << std::endl;
	std::cout << "animal variable is of type " << animal->getType() << "."
		<< std::endl;
	std::cout << "cat variable is of type " << cat->getType() << "."
		<< std::endl;
	std::cout << "dog variable is of type " << dog->getType() << "."
		<< std::endl;
	std::cout << "----------------------------------------------------"
		<< std::endl;
	std::cout << "DISPLAY THE BRAINS OF ANIMAL'S OBJECT" << std::endl;
	std::cout << "[CAT WITH BRAIN]" << std::endl;
	for (i = 0; i < catWithBrain.getBrain()->getLength(); i++)
		std::cout << catWithBrain.getBrain()->getIdea(i) << std::endl;
	std::cout << "[DOG WITH BRAIN]" << std::endl;
	for (i = 0; i < dogWithBrain.getBrain()->getLength(); i++)
		std::cout << dogWithBrain.getBrain()->getIdea(i) << std::endl;

	std::cout << "ANIMALS MAKING SOUNDS" << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "===================================================="
		<< std::endl << "WRONG ANIMALS TURN" << std::endl
		<< "====================================================" << std::endl;

	std::cout << "DISPLAY THE TYPES OF WRONG ANIMAL'S OBJECT" << std::endl;
	std::cout << "wrongAnimal variable is of type " << wrongAnimal->getType() << "."
		<< std::endl;
	std::cout << "wrongCat variable is of type " << wrongCat->getType() << "."
		<< std::endl;
	std::cout << "----------------------------------------------------"
		<< std::endl;

	std::cout << "WRONG ANIMALS MAKING SOUNDS" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << "SAD DESTRUCTION FOR EVERY ANIMAL" << std::endl;
	delete animal;
	delete cat;
	delete dog;
	delete wrongAnimal;
	delete wrongCat;

	return (0);
}
